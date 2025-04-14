#pragma once
#include "Car.h"

class SportsCar : public Car
{
public:
	bool bTurbo;
	voud setTurbo(bool bTur) { bTurbo = bTur; }
	void speedUp() {
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};
