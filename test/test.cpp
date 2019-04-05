#include "../catch.hpp"
#include "Device.h"
#include "catchCustom.hpp"
#include <stdlib.h>

#define SAMPLES 100

using Catch::Contains;

TEST_CASE("Data validation")
{
	Device testDevice(SAMPLES);
	REQUIRE(testDevice.data.size() == SAMPLES);
	
	SECTION("Check if device names are valid"){
		std::array<std::string, 3> message;
		for(int i = 0 ; i < SAMPLES ; ++i)
		{
			message = testDevice.data[i];
			
			REQUIRE_THAT(message[0],
				Contains("LIGHT_SENSOR") || Contains("PARKING_SENSOR")  || Contains("TEMPERATURE_SENSOR") || Contains("POSITION_SENSOR") || Contains("HAL_SENSOR"));
		}
	}

	SECTION("Check if status names are valid"){
		std::array<std::string, 3> message;
		for(int i = 0 ; i < SAMPLES ; ++i)
		{
			message = testDevice.data[i];
			
			REQUIRE_THAT(message[1],
				Contains("OK") || Contains("WARNING")  || Contains("FAILURE") );
		}
	}

		SECTION("Check if hex values are valid"){
		std::array<std::string, 3> message;
		for(int i = 0 ; i < SAMPLES ; ++i)
		{
			message = testDevice.data[i];
			long long hex = (long long)strtol(message[2].c_str(), 0, 16);

			REQUIRE_THAT( hex, IsBetween( 0, 0xFFFFFFFFFF ) );
		}
	}
	SECTION("Check if stack overflow helps"){
		CHECK("foo" == "bar");
	}
}


