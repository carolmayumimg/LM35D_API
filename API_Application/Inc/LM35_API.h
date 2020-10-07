/*
 * LM35_API.h
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

#ifndef LM35_API_H_
#define LM35_API_H_
#include "stm32f4xx_hal.h"

void Init_API(ADC_HandleTypeDef *adc_hand);
float Return_Temperature(void);
uint8_t Temperature_LT(float t);
uint8_t Temperature_GT(float t);
uint8_t Temperature_InGap(float temp_inf, float temp_sup);

#endif /* LM35_API_H_ */
