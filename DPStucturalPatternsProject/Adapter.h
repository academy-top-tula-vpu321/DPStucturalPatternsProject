#pragma once
#include <iostream>

class ISensorAdapter
{
public:
	virtual float GetSensorData() = 0;
	virtual ~ISensorAdapter() {}
};

class SensorCelsius
{
public:
	virtual float GetTemperature()
	{
		return 36.6;
	}
	// other code
};

class SensorFahrenheit
{
public:
	float GetTemperatureFahrenheit()
	{
		return 25.5;
	}
	// other code
};

class AdapterCelsius : public ISensorAdapter
{
	SensorCelsius* sensor;
public:
	AdapterCelsius(SensorCelsius* sensor) : sensor{ sensor } {}
	~AdapterCelsius() { delete sensor; }

	float GetSensorData() override
	{
		return sensor->GetTemperature();
	}
};

class AdapterFahrenheit : public ISensorAdapter
{
	SensorFahrenheit* sensor;
public:
	AdapterFahrenheit(SensorFahrenheit* sensor) : sensor{ sensor } {}
	~AdapterFahrenheit() { delete sensor; }

	float GetSensorData() override
	{
		return sensor->GetTemperatureFahrenheit();
	}
};

class Client
{
public:
	void ClientMethod()
	{
		ISensorAdapter* sensor = new AdapterCelsius(new SensorCelsius());
		std::cout << sensor->GetSensorData() << "\n";

		delete sensor;

		sensor = new AdapterFahrenheit(new SensorFahrenheit());
		std::cout << sensor->GetSensorData() << "\n";

		delete sensor;
	}
};
