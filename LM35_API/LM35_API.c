/*
 * LM35_API.c
 * Copyright (C) 2020 Eduardo Tschaen Filho <tschaenfilho@gmail.com>
 * Copyright (C) 2020 Carolina Mayumi M. Guimarães <carolmmg@hotmail.com>
 * Version 1.0 - API with the following implemented functions:
 * void Init_API(ADC_HandleTypeDef *adc_hand);
 * float Return_Temperature(void);
 * int Temperature_LT(float t);
 * int Temperature_GT(float t);
 * int Temperature_InGap(float temp_inf, float temp_sup);
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 *  with this program; if not, If not, see <https://www.gnu.org/licenses/>
 *
 * Created on: 3 de out de 2020
 * Institution: UFMG
 *
 * This API contains functions to read and deal with data from the
 * temperature sensor LM35D, using the ADC peripheral in polling mode.
 */

#include "LM35_API.h"
#include "main.h"

/*
 * The temperature range of LM35D is 0°C to 100°C
 * The gain is 10mV/°C
 * The factor to convert the result of the ADC conversion to °C is: 3.3/4095*100
 * See LM35 datasheet for more details.
 */

ADC_HandleTypeDef *adc_hand;

/*
 * This function receives the ADC handle used by the sensor
 * adc_hand_ext: ADC handle used in the application (e.g., hadc1, hadc2);
 */
void Init_API(ADC_HandleTypeDef *adc_hand_ext){
	adc_hand = adc_hand_ext;
}

/*
 * This function gets the temperature value read by the sensor in Celsius.
 * Return: temperature in °C, between 0°C and 100°C, if there was no errors
 * 		   -1 if ADC state is busy
 * 		   -2 if there was an error during the ADC conversion
 */
float Return_Temperature(void){
	float temperature;
	// Check if ADC state is not busy
	if(HAL_ADC_GetState(adc_hand) != HAL_ADC_STATE_REG_BUSY){
		// Start the conversion
		HAL_ADC_Start(adc_hand);
		if(HAL_ADC_PollForConversion(adc_hand, 100) == HAL_OK)
			// Return the temperature if there was no errors
			temperature = HAL_ADC_GetValue(adc_hand)*3.3/4095*100;
		else
			// In case of error
			temperature = -2;
		// Stop the conversion
		HAL_ADC_Stop(adc_hand);

		return temperature;
	}
	// If ADC state is busy
	return -1;
}

/*
 * This function checks if the temperature value read by the sensor
 * is lower than the parameter temp.
 * temp: value of temperature to compare, in Celsius.
 * Return: 1 if the value read is lower than temp
 * 		   0 if the value read is greater than or equal to temp
 * 		   -1 if ADC state is busy
 */
uint8_t Temperature_LT(float temp){
	float temperature;
	// Check if ADC state is not busy
	if(HAL_ADC_GetState(adc_hand) != HAL_ADC_STATE_REG_BUSY){
		// Start the conversion and put the result in the variable
		HAL_ADC_Start(adc_hand);
		HAL_ADC_PollForConversion(adc_hand, 100);
		temperature = HAL_ADC_GetValue(adc_hand)*3.3/4095*100;
		// Stop the conversion
		HAL_ADC_Stop(adc_hand);
		// Compare the values
		if(temperature < temp)
			return 1;
		return 0;
	}
	// If ADC state is busy
	return -1;
}

/*
 * This function checks if the temperature value read by the sensor
 * is greater than the parameter temp.
 * temp: value of temperature to compare, in Celsius.
 * Return: 1 if the value read is greater than temp
 * 		   0 if the value read is lower than or equal to temp
 * 		   -1 if ADC state is busy
 */
uint8_t Temperature_GT(float temp){
	float temperature;
	// Check if ADC state is not busy
	if(HAL_ADC_GetState(adc_hand) != HAL_ADC_STATE_REG_BUSY){
		// Start the conversion and put the result in the variable
		HAL_ADC_Start(adc_hand);
		HAL_ADC_PollForConversion(adc_hand, 100);
		temperature = HAL_ADC_GetValue(adc_hand)*3.3/4095*100;
		// Stop the conversion
		HAL_ADC_Stop(adc_hand);
		// Compare the values
		if(temperature > temp)
			return 1;
		return 0;
		}
	// If ADC state is busy
	return -1;
}

/*
 * This function checks if the temperature value read by the sensor
 * is between than the parameters temp_inf and temp_sup.
 * temp: value of temperature to compare, in Celsius.
 * Return: 1 if the value read is between temp_inf and temp_sup
 * 		   0 if the value read is not between temp_inf and temp_sup
 * 		   -1 if ADC state is busy
 */
uint8_t Temperature_InGap(float temp_inf, float temp_sup){
	float temperature;
	// Check if ADC state is not busy
	if(HAL_ADC_GetState(adc_hand) != HAL_ADC_STATE_REG_BUSY){
		// Start the conversion and put the result in the variable
		HAL_ADC_Start(adc_hand);
		HAL_ADC_PollForConversion(adc_hand, 100);
		temperature = HAL_ADC_GetValue(adc_hand)*3.3/4095*100;;
		// Stop the conversion
		HAL_ADC_Stop(adc_hand);
		// Compare the values
		if(temperature >= temp_inf && temperature <= temp_sup)
			return 1;
		return 0;
		}
	// If ADC state is busy
	return -1;
}
