/*
 * Mini_project.c
 *
 *  Created on: Aug 20 , 2022
 *      Author: Tarek Ahmed Abd El Wahab Ali
 *      
 *      Vehicle
 */
#include <stdio.h>
#include <string.h> // For ON and OFF state
#include "sensor.h" //Sensor Functions

#define ENGINE_TEMP_CONTROLLER 1 //For bonus question

int main(void)
{
	unch start_program , selected_sensor;//System Option
	unch ReOpen_the_sysem=1;// Restart the system
	unch ReOpen_SensorMenu;// Restart sensor menu
	//For Menu Of Sensors:
	int speed=0;//Speed of vehicle
	float room_temperature=0;//Room Temperature Sensor
	float Engine_temperature=0;//Engine Temperature Sensor

	unch Engine[]="OFF";//Engine State
	unch AC[]="OFF";// Air Conditioner State
	unch Engine_temp_controller[]="OFF";//Engine Temperature Controller State


	setbuf(stdout,NULL);

	while(1==ReOpen_the_sysem)// If false return to main option (start system again)
	{
		printf("a.Turn on vehicle engine\n"
				"b.Turn off vehicle engine\n"
				"c.Quit the system\n");
		scanf(" %c",&start_program);

		switch(start_program)
		{

		case 'a'://Engine turn on

			ReOpen_SensorMenu=1;//To make condition true

			while(1==ReOpen_SensorMenu)//If false out from the program
			{
				//Sensor Menu:
				printf("a.Turn off the engine\n"
						"b. Set the traffic light color\n"
						"c. Set the room temperature (Temperature Sensor)\n");
#if ENGINE_TEMP_CONTROLLER
				printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
#endif

				scanf(" %c",&selected_sensor);


				if('a'==selected_sensor)//Turn off the engine and return to main system
				{
					printf("a.Turn off the engine\n\n");
					strcpy(Engine,"OFF");
					ReOpen_SensorMenu=0;

				}
				else if('b'==selected_sensor)//calculating the speed
				{
					traffic_speed(&speed);
					strcpy(Engine,"ON ");

				}

				else if('c'==selected_sensor)//calculating room temperature and state of AC
				{
					room_temp(&room_temperature,AC);
					strcpy(Engine,"ON ");
				}
#if ENGINE_TEMP_CONTROLLER
				else if('d'==selected_sensor)//calculating Engine temperature and state of engine temperature controller
				{
					engine_temp(&Engine_temperature,Engine_temp_controller);
					strcpy(Engine,"ON ");
				}
#endif
				else
				{
					printf("Wrong choice\n");
				}

				if(30==speed)
				{
					room_temperature=(room_temperature*(1.25))+1;//if speed =30 do this operation if not return original value (room temperature)
#if ENGINE_TEMP_CONTROLLER
					Engine_temperature=(Engine_temperature*(1.25))+1;//if speed =30 do this operation if not return original value (engine temperature)
#endif
				}
				printf("Engine is %s\n",Engine);
				printf("Air condition is %s\n",AC);
				printf("Speed now is %d Km/hr\n",speed);
				printf("Room temperature is %f C\n",room_temperature);
#if ENGINE_TEMP_CONTROLLER
				printf("Engine controller state is %s\n",Engine_temp_controller);
				printf("Engine temperature is %f C\n\n",Engine_temperature);

#endif
			}

			break;


		case 'b'://Engine turn off
			printf("Turn off vehicle engine\n"
					"\n");
			break;

		case 'c'://Quit the system
			printf("Quit the system\n"
					"\n");
			ReOpen_the_sysem=0;
			break;

		default:
			printf("wrong choice please enter right choice\n"
					"\n");
		}
	}

	return 0;
}

