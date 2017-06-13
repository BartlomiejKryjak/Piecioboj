#include "competition.h"
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>

void Competition::trainingSessions(Player* players[], int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		int number = rand()%10; //losujemy liczbę treningów

		for (int j = 0; j < number; j++) //trenujemy
		{
			if (rand()%100 < (players[i]->getInjuryPercent()/10)) //jak ma pecha
			{
				players[i]->setInjury(); //to kontuzja
				break; //i nie trenuje dalej
			}
			if (players[i]->getInjuryStatus()) break; //jak ma kontuzję, to nie trenuje

			int what = rand()%5; //a jak trenuje, to losujemy co
			switch(what)
			{
				case 0: players[i]->setFencing(players[i]->getFencing()+2); break;
				case 1: players[i]->setSwimming(players[i]->getSwimming()+2); break;
				case 2: players[i]->setHorseRiding(players[i]->getHorseRiding()+2); break;
				case 3: players[i]->setRunning(players[i]->getRunning()+2); break;
				case 4: players[i]->setShooting(players[i]->getShooting()+2); break;
			}
			players[i]->setInjuryPercent(players[i]->getInjuryPercent()-0.1); //mniejsza szansa na kontuzję
		}
	}
}

void Competition::fencingCompetition(Player* players[], int numberOfPlayers)
{
	int winCounter[numberOfPlayers] = {0};
	int first, second;

	for (int i = 0; i < numberOfPlayers; i++)
	{
		for (int j = i+1; j < numberOfPlayers; j++)
		{
			first = i;
			second = j;

			if ((i+j)%2)
				std::swap(first, second);

			//sprawdzenie, czy ktoś z nich nie jest kontuzjowany
			if (players[first]->getInjuryStatus())
			{
				if (!(players[second]->getInjuryStatus())) //jeżeli drugi zdrowy
					winCounter[second]++;
				continue;
			}
			else if (players[second]->getInjuryStatus()) //jeżeli drugi kontuzjowany
			{
				winCounter[first]++; //to pierwszy na pewno nie jest, więc wygrywa
				continue;
			}

			for (int tick = 0; tick < 180; tick++) //wszyscy zdrowi, walczymy
			{
				//zawsze zaczyna ten z niższym numerem startowym
				if (rand()%100<70) //70% szans na atak
				{
					//może czas na  kontuzję?
					if (rand()%100<players[first]->getInjuryPercent())
					{
						players[first]->setInjury(); //kontuzjowany
						winCounter[second]++; //wygrywa drugi
						break; //kończymy
					}
					else if(rand()%100<(players[first]->getFencing())) //jeżeli uda mu się trafić
					{
						winCounter[first]++; //wygrywa
						break; //i kończymy
					}
				}
				else if (rand()%100<70) //70% szans na atak
				{
					//drugi też może być kontuzjowany
					if (rand()%100<players[second]->getInjuryPercent())
					{
						players[second]->setInjury(); //kontuzjowany
						winCounter[first]++; //wygrywa pierwszy
						break; //kończymy
					}
					else if(rand()%100<(players[second]->getFencing())) //i uda mu się trafić
					{
						winCounter[second]++; //to wygrywa
						break; //i kończymy
					}
				}
			}
		}
	}

	for (int i = 0; i < numberOfPlayers; i++) //przyznajemy punkty
		players[i]->addPoints(1000 + (winCounter[i]-numberOfPlayers*3/4)*(1000.0/numberOfPlayers));

}

void Competition::swimmingCompetition(Player* players[], int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if (players[i]->getInjuryStatus())
			continue;

		if (rand()%100<players[i]->getInjuryPercent())
		{
			players[i]->setInjury();
			continue;
		}
		else players[i]->addPoints(1000+(players[i]->getSwimming()-29)*12);
	}
}

void Competition::horseRidingCompetition(Player* players[], int numberOfPlayers)
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if (players[i]->getInjuryStatus())
			continue; //kontuzjowani nie jeżdżą

		int whipRound = 0;
		for (int j = 0; j < 15; j++) //12 przeszkód, w tym podwójna i potrójna, czyli 15
		{
			if (rand()%100>players[i]->getHorseRiding()+40) //niepowodzenie
			{
				if (rand()%100<players[i]->getHorseRiding()) //upadek
				{
					whipRound+=3;
					if (rand()%100<players[i]->getInjuryPercent()) //kontuzja
					{
						players[i]->setInjury();
						break;
					}
				}
				else if (rand()%100<players[i]->getHorseRiding()+20) //odmowa skoku
					whipRound+=2;
				else whipRound++; //po prostu zrzutka
			}
		}
		if(!players[i]->getInjuryStatus()) //jeżeli ukończył
			players[i]->addPoints(1200-20*whipRound+
				([](int stat)->int
				{
					if (stat > 29) return 29;
					else return stat;
				}(players[i]->getHorseRiding())-29)*8);
			//baza - niepowodzenia - punkty karne za czas
	}
}

void Competition::runningCompetition(Player* players[], int numberOfPlayers)
{
	int defaultTime = 600 + 3*35; //10 minut na bieg, 35 sekund na każde strzelanie
	int timeElapsed = 0;
	int hits = 0;
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if(players[i]->getInjuryStatus()) //jeżeli kontuzjowany
			{
				players[i]->addPoints(-players[i]->getPoints()); //odejmujemy mu wszystkie punkty - czyli nie ukończył
				continue;
			}
		while(hits<15) //strzelanie
		{
			if (rand()%100<players[i]->getShooting())
				hits++; //trafienie
			timeElapsed++;
			if (timeElapsed >= 210) break; //przekroczony czas na strzelanie
		}
		timeElapsed += (600-(players[i]->getRunning()-29)*2); //czas biegu
		players[i]->addPoints(1200+(defaultTime-timeElapsed)*3); //punkty

		//wyzerowanie osiągnięć zawodnika
		timeElapsed = 0;
		hits = 0;
	}
}

void Competition::makeWinners(Player* players[], int numberOfPlayers)
{
	//Sortowanie tablicy z graczami
	for (int i = 0; i < numberOfPlayers; i++)
		for (int j = 0; j < numberOfPlayers-1; j++)
			if (players[j]->getPoints() < players[j+1]->getPoints())
				std::swap(players[j], players[j+1]);

	//Zapisujemy wyniki

	FILE * results = fopen("results.csv", "w");

	fprintf(results ,"Miejsce\t\tNr startowy\tPunkty\n");

	for (int i = 0; i < numberOfPlayers; i++)
		fprintf(results ,"%4d\t\t%7d\t\t%5s\n", i+1, players[i]->getStartingNumber(),
						[](int points)-> const char*
						{
							if (!points)
								return "DNF";
							else
							{
								char temp[5];
								char* pointer = temp;
								int tempPoints = points;
								for (int i = 3; i >= 0; i--)
								{
									temp[i] = tempPoints%10 + '0';
									tempPoints/=10;
								}
								temp[4] = '\0';
								return pointer;
							}
						}(players[i]->getPoints()));

	//Zapisujemy statystyki

	FILE * stats = fopen("stats.csv", "w");

	fprintf(stats, "Oznaczenia:\n# - Numer startowy - Starting number\nFN - Szermierka - Fencing\nSW - Pływanie - Swimming\nHR - Jazda konna - Horse riding\nRN - Bieganie - Running\nSH - Strzelanie - Shooting\nPT - Punkty - Points\n\n");
	fprintf(stats, "   #\tFN\tSW\tHR\tRN\tSH\t PT\n");

	for (int i = 0; i < numberOfPlayers; i++)
		fprintf(stats, "%4d\t%2d\t%2d\t%2d\t%2d\t%2d\t%4d\n",
					players[i]->getStartingNumber(), players[i]->getFencing(),
					players[i]->getSwimming(), players[i]->getHorseRiding(),
					players[i]->getRunning(), players[i]->getShooting(),
					players[i]->getPoints());

}
