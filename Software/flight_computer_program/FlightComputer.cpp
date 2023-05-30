#include "StaticVariables.h"
#include "StateMachine.h"
#include "SensorData.h"
#include "FlightComputer.h"

bool FlightComputer::start_health_check(){
    return true;
}

bool FlightComputer::mid_flight_health_check(){

}


void FlightComputer::retrieve_data(){
    //get data through canbus and set it to sensor_data
}

//Main
void FlightComputer::main_loop(){

    while (AbleToFly)
    {
        retrieve_data();
        mid_flight_health_check();
        flight_function.set_variables();
        flight_function.call_function();
    }
}

void FlightComputer::init(){
    retrieve_data();
    if(start_health_check()){
        main_loop();
    }
}

