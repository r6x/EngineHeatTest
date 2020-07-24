#pragma once
#include <vector>

namespace Engines
{
	struct engine {
		float heatingSpeed();
		float coolingSpeed(float currentEngineTemperature, int ambientTemperature);
		float momentOfInertia = 10;
		float overHeatTemperature = 110;
		float torqueHeatRatio = 0.01;
		float rotationSpeedHeatRatio = 0.0001;
		float coolingRateRatio = 0.1;
		std::vector<float> momentOfPower = { 20,75,100,105,75,0 };
		std::vector<float> rotationSpeed = { 0,75,150,200,250,300 };
		float acceleration = 0;
		float currentMoment = 0;
		float currentRotationSpeed = 0;
	};
}