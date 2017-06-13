#include "player.h"
#include "competition.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>

int main(int argc, char* const argv[])
{
	int numberOfPlayers = 32;
	srand(time(NULL));
	Player* players[numberOfPlayers];
	for (int i = 0; i < numberOfPlayers; i++)
		players[i] = new Player(i);

	//Czas na treningi!

	Competition::trainingSessions(players, numberOfPlayers);

	//Zawody czas zacząć!

	Competition::fencingCompetition(players, numberOfPlayers);

	Competition::swimmingCompetition(players, numberOfPlayers);

	Competition::horseRidingCompetition(players, numberOfPlayers);

	Competition::runningCompetition(players, numberOfPlayers);

	//Wyłońmy zwycięzców

	Competition::makeWinners(players, numberOfPlayers);

}
