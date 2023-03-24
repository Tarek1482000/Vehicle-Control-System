/*
 * sensor.h
 *
 *  Created on: Aug 25, 2022
 *      Author: tarek
 */

#ifndef SENSOR_H_
#define SENSOR_H_

typedef unsigned char unch;


void traffic_speed(int *ptr_speed) ;

void room_temp( float *room_temp_ptr,unch *Air_con);

void engine_temp(float *engine_temp_ptr,unch *engine_temp_contr);

#endif /* SENSOR_H_ */
