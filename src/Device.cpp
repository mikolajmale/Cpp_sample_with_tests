#include "Device.h"

Device::Device(const int samples)
{
	createSampleDataBase(samples);

	std::array<std::string, 3> message;
	std::string line;
	std::ifstream data_file("data.txt"); 
	if (data_file.is_open())
	{
		while (std::getline(data_file , line))
		{
			size_t pos = 0;
			std::string token;
			int i = 0;
			while ((pos = line.find(',')) != std::string::npos) {
				token = line.substr(0, pos);
				message[i++] = token;
				line.erase(0, pos + 1);
				if (i == 2) message[2] = line;
			}
			data.push_back(message);

		}
		data_file.close();
	}
	
}


Device::~Device()
{
}

void Device::createSampleDataBase(int samples)
{
	srand((unsigned)time(NULL));
	int device = 0, state = 0;
	long long hex1 = 0, hex2 = 0, hex3 = 0;
	std::ofstream data_file("data.txt");
	for (int i = 0; i < samples; ++i)
	{
		device = rand() % 5;
		state = rand() % 3;
		hex1 = rand() % 0xFFFF;
		hex2 = rand() % 0xFFFF;
		hex3 = rand() % 0xFF;
		long long unsigned hex = (hex1 << 24) | (hex2 << 8) | (hex3);

		std::stringstream str;

		data_file << printDevice(device) << "," << printState(state) << "," << std::hex << hex << std::endl;
		str << std::hex << hex;
		std::bitset<40> binary(hex);
	}
	data_file.close();
}



std::string Device::printState(int state)
{
	std::string state_string;
	switch (state)
	{
	case OK:
		state_string = "OK";
		break;
	case WARNING:
		state_string = "WARNING";
		break;
	case FAILURE:
		state_string = "FAILURE";
		break;
	default:
		break;
	}

	return state_string;
}

std::string Device::printDevice(int devices)
{
	std::string sensor;
	switch (devices)
	{
	case LIGHT_SENSOR:
		sensor = "LIGHT_SENSOR";
		break;
	case PARKING_SENSOR:
		sensor = "PARKING_SENSOR";
		break;
	case TEMPERATURE_SENSOR:
		sensor = "TEMPERATURE_SENSOR";
		break;
	case POSITION_SENSOR:
		sensor = "POSITION_SENSOR";
		break;
	case HAL_SENSOR:
		sensor = "HAL_SENSOR";
		break;
	default:
		break;
	}
	return sensor;
}

void Device::printFailedDevices(void)
{
	std::array<std::string , 3> message;
	long long hex = 0;
	for(unsigned int i = 0 ; i < data.size() ; ++i)
	{
		message = data[i];
		if(message[1] == "FAILURE")
		{
			hex = (long long)strtol(message[2].c_str(), 0, 16);
			std::cout << message[0] << " , " << std::bitset<40>(hex) << '\n';
		}
	}
}


