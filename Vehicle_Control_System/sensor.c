/*
 * sensor.c
 *
 *  Created on: Mar 24, 2023
 *      Author: tarek
 */


#include "sensor.h"


void traffic_speed(int *ptr_speed) //calculate speed
{

	unch traffic_light_color;
	printf("If traffic light is green press G\n"
			"if orange press O\n"
			"if red press R\n");

	scanf(" %c",&traffic_light_color);
	switch(traffic_light_color)
	{
	case'G':
	case'g':
		*ptr_speed=100;
		break;
	case'O':
	case'o':
		*ptr_speed=30;
		break;
	case'R':
	case'r':
		*ptr_speed=0;
		break;

	default:
		printf("Error\n");
	}
}




void room_temp( float *room_temp_ptr,unch *Air_con)//calculate room temperature and state of AC
{
	float room_t;
	printf("Enter room temperature\n");
	scanf("%f",&room_t);

	if(room_t<10 || room_t>30)
	{
		room_t=20;
		strcpy(Air_con,"ON ");
	}
	else
	{
		strcpy(Air_con,"OFF");
	}

	*room_temp_ptr=room_t;

}


void engine_temp(float *engine_temp_ptr,unch *engine_temp_contr)//calculate engine temperature and state of Engine Temperature Controller
{
	float engine_t;
	printf("Enter engine temperature\n");
	scanf("%f",&engine_t);

	if(engine_t>150 || engine_t<100)
	{
		engine_t=125;

		strcpy(engine_temp_contr,"ON ");
	}
	else
	{
		strcpy(engine_temp_contr,"OFF");
	}
	*engine_temp_ptr=engine_t;
}
