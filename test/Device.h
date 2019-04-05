#pragma once
#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <ctime>
#include <string>
#include <array>
#include <vector>
#include <sstream> 
#include <bitset>
#include <stdlib.h>

class Device
{
public:
	Device(const int samples);
	~Device();


	void printFailedDevices(void);
	void createSampleDataBase(int);
	std::string printState(int state);
	std::string printDevice(int devices);

	enum STATES
	{
		OK,
		WARNING,
		FAILURE
	};

	enum DEVICES
	{
		LIGHT_SENSOR,
		PARKING_SENSOR,
		TEMPERATURE_SENSOR,
		POSITION_SENSOR,
		HAL_SENSOR
	};

	std::vector<std::array<std::string, 3>> data;

};

