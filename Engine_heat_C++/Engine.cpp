#include "Engine.h"

namespace Engines
{
	float engine::heatingSpeed() {
		return currentMoment * torqueHeatRatio + currentRotationSpeed * currentRotationSpeed * rotationSpeedHeatRatio;
	}

	float engine::coolingSpeed(float currentEngineTemperature, int ambientTemperature) {
		return coolingRateRatio * (ambientTemperature - currentEngineTemperature);
	}
}