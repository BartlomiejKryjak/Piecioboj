#pragma once

class Player
{
private:
	int fencing;
	int swimming;
	int horseRiding;
	int running;
	int shooting;
	int startingNumber;
	bool injuried;
	float injuryPercent;

	int points;

public:
	void setFencing(int value);
	void setSwimming(int value);
	void setHorseRiding(int value);
	void setRunning(int value);
	void setShooting(int value);
	void setStartingNumber(int number);
	void setInjury();
	void setInjuryPercent(int value);
	void addPoints(int value);

	int getFencing();
	int getSwimming();
	int getHorseRiding();
	int getRunning();
	int getShooting();
	int getStartingNumber();
	bool getInjuryStatus();
	float getInjuryPercent();
	int getPoints();

	Player(int number);
};
