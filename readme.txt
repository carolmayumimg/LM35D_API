The LM35_API API provides some functions to read and deal with data from the temperature sensor LM35D.

It was developed to be used with STM32F4 microcontrolers. It uses the ADC peripheral in polling mode, with HAL library functions.

----------
Functions:

void Init_API(ADC_HandleTypeDef *adc_hand_ext);
Receives the ADC handle used by the sensor, that will be used in the other functions.
- adc_hand_ext: is the ADC handle used in the application (e.g., hadc1, hadc2);

float Return_Temperature();
Returns the temperature value read by the sensor in Celsius. 

uint8_t Temperature_LT(float temp);
Checks if the temperature value read by the sensor is lower than the parameter temp. Returns 1 if is lower, 0 if is greater or equal, and -1 if there was some error in the comunication.
- temp: value of temperature to compare, in Celsius.

uint8_t Temperature_GT(float temp);
Checks if the temperature value read by the sensor is greater than the parameter temp. Returns 1 if is greater, 0 if is lower or equal, and -1 if there was some error in the comunication.
- temp: value of temperature to compare, in Celsius.

uint8_t Temperature_InGap(float temp_inf, float temp_sup);
Checks if the temperature value read by the sensor is between than the parameters temp_inf and temp_sup. Returns 1 if is between these values, 0 if is lower or equal than t_inf or greater or equal than t_sup, and -1 if there was some error in the comunication.
- temp_inf: inferior value of temperature to compare, in Celsius.
- temp_sup: superior value of temperature to compare, in Celsius.
----------

An application was developed using the LM35_API, and is the API_Application folder. 

It utilizes a LM35D sensor and an RGB LED (common cathode) with an STM32F4 microcontroller.

In case of doubts or problems, please contact the developers:
Carolina Mayumi M. Guimarães - carolmmg@hotmail.com
Eduardo Tschaen Filho - tschaenfilho@gmail.com
