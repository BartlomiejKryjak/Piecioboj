#include "player.h"
#include <cstdlib>
#include <ctime>

#pragma mark [Ustalanie danych]

void Player::setFencing(int value)
{
	this -> fencing = value;
}

void Player::setSwimming(int value)
{
	this -> swimming = value;
}

void Player::setHorseRiding(int value)
{
	this -> horseRiding = value;
}

void Player::setRunning(int value)
{
	this -> running = value;
}

void Player::setShooting(int value)
{
	this -> shooting = value;
}

void Player::setStartingNumber(int number)
{
	this -> startingNumber = number;
}

void Player::setInjury()
{
	this -> injuried = true;
}

void Player::setInjuryPercent(int value)
{
	this -> injuryPercent = value;
}

void Player::addPoints(int value)
{
	this -> points += value;
}

#pragma mark [Pobieranie danych]

int Player::getFencing()
{
	return this -> fencing;
}

int Player::getSwimming()
{
	return this -> swimming;
}

int Player::getHorseRiding()
{
	return this -> horseRiding;
}

int Player::getRunning()
{
	return this -> running;
}

int Player::getShooting()
{
	return this -> shooting;
}

int Player::getStartingNumber()
{
	return this -> startingNumber;
}

bool Player::getInjuryStatus()
{
	return this -> injuried;
}

float Player::getInjuryPercent()
{
	return this -> injuryPercent;
}

int Player::getPoints()
{
	return this -> points;
}

#pragma mark [Tworzenie zawodnika]

Player::Player(int number)
{
	fencing = rand()%36+5;
	swimming = rand()%36+5;
	horseRiding = rand()%36+5;
	running = rand()%36+5;
	shooting = rand()%36+5;
	startingNumber = number+1;
	injuried = false;
	injuryPercent = 1.0;

	points = 0;

	int best = rand()%5; //losujemy jego najlepszą statystykę
	int bestAdd = rand()%10+20; //i dodajemy coś z zakresu 20-30

	switch(best)
	{
		case 0: fencing += bestAdd; break;
		case 1: swimming += bestAdd; break;
		case 2: horseRiding += bestAdd; break;
		case 3: running += bestAdd; break;
		case 4: shooting += bestAdd; break;
	}
}
