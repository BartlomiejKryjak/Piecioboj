#pragma once

#include "player.h"

class Competition
{
public:
	static void trainingSessions(Player* players[], int numberOfPlayers);
	static void fencingCompetition(Player* players[], int numberOfPlayers);
	static void swimmingCompetition(Player* players[], int numberOfPlayers);
	static void horseRidingCompetition(Player* players[], int numberOfPlayers);
	static void runningCompetition(Player* players[], int numberOfPlayers);
	static void makeWinners(Player* players[], int numberOfPlayers);
};
