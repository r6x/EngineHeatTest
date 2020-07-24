#pragma once
#include "Engine.h"

namespace TestStands {

	template <typename T>
	class overHeatingTest {
	public:
		int start();
		overHeatingTest(T& engine, float ambientTemperature);
		T* engine;
	private:
		float ambientTemperature;
		float currentEngineTemperature;
		

	};
	template <typename T>
	overHeatingTest<T>::overHeatingTest(T& engine, float ambientTemperature) {
		this->engine = &engine;
		currentEngineTemperature = ambientTemperature;
		this->ambientTemperature = ambientTemperature;
	}

	template <typename T>
	int overHeatingTest<T>::start() {
		int i = 1, time = 0;
		float previousEngineTemperature = 0;
		while (currentEngineTemperature < engine->overHeatTemperature) {
			
			engine->currentMoment = (engine->momentOfPower[i] - engine->momentOfPower[i - 1]) * (engine->currentRotationSpeed - engine->rotationSpeed[i - 1]) /
				(engine->rotationSpeed[i] - engine->rotationSpeed[i - 1]) + engine->momentOfPower[i - 1];
			engine->acceleration = engine->currentMoment / engine->momentOfInertia;
			engine->currentRotationSpeed += engine->acceleration;
			if (engine->currentRotationSpeed >= engine->rotationSpeed[i])
			{
				i++;
			}
			currentEngineTemperature = currentEngineTemperature + engine->heatingSpeed() -
				engine->coolingSpeed(ambientTemperature, currentEngineTemperature);
			if (engine->heatingSpeed()-engine->coolingSpeed(ambientTemperature, currentEngineTemperature)<0.001)
			{
				return -1;
			}
			previousEngineTemperature = currentEngineTemperature;
			time++;
		}
		return time;
	}
}

