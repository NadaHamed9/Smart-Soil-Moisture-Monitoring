/*
 ================================================================================================
 Name        : main.c
 Author      : Karim Gomaa
 Description :
 Date        : 2/27/2023
 ================================================================================================
 */

#include <avr/io.h>
#include "lcd.h"
#include "gpio.h"
#include "std_types.h"
#include "adc.h"
#include "buzzer.h"
#include <util/delay.h>

#define SOIL_SENSOR_NUMBER 7
#define WATER_LEVEL_SENSOR 600
#define SOIL_MOISTURE_SENSOR 500

int measuring_soil=0;
uint16 measuring_soil_percentage=0;
uint16 measuring_tank=0;
uint16 measuring_tank_percentage=0;

void read_SENSORS(){

	measuring_soil = ADC_readChannel(SOIL_SENSOR_NUMBER);  /* reading soil moisture value */
	measuring_soil_percentage=100-(measuring_soil*100.00)/1023.00;
	measuring_tank= ADC_readChannel(0); /* read water tank sensor */
	measuring_tank_percentage=(measuring_tank*100.00)/1023.00;
	LCD_moveCursor(0, 12);
	LCD_intgerToString(measuring_tank_percentage);
	LCD_displayString("% ");
	LCD_moveCursor(1, 12);
	LCD_intgerToString(measuring_soil_percentage);
	LCD_displayString("% ");
	_delay_ms(100);

}


void lcd_WETSOIL(){
	LCD_moveCursor(0, 0);
	LCD_displayString("WET SOIL^_^");
	LCD_moveCursor(1, 0);
	LCD_displayString("           ");
	_delay_ms(200);
}

void lcd_DRYSOIL(){
	LCD_moveCursor(0, 0);
	LCD_displayString("DRY SOIL-_-");

	LCD_moveCursor(1, 0);
	LCD_displayString("*WATERING*");
	_delay_ms(200);

}

void pump_OFF(){
	GPIO_writePin(PORTB, PIN1, LOGIC_LOW);

}
void pump_ON(){
	GPIO_writePin(PORTB, PIN1, LOGIC_HIGH);
}


int  main()
{
	GPIO_setupPinDirection(PORTA, PIN0, PIN_INPUT);
	GPIO_setupPinDirection(PORTA, PIN7, PIN_INPUT);
	GPIO_setupPinDirection(PORTB, PIN1, PIN_OUTPUT);  /*Water pump sensor pin    */
	GPIO_writePin(PORTB, PIN1, LOGIC_LOW);

	ADC_ConfigType ADC_Config;
	ADC_Config.ref_volt=VOLT_2_56;
	ADC_Config.prescaler=PRESCALER_128;
	ADC_init(&ADC_Config);

	BUZZER_init();
	LCD_init();
	LCD_clearScreen();
	BUZZER_off();

	while(1)
	{
		read_SENSORS();
		if(measuring_soil > SOIL_MOISTURE_SENSOR)
		{
			lcd_DRYSOIL();
			if(measuring_tank<WATER_LEVEL_SENSOR)
			{
				BUZZER_on();
				pump_OFF();
				while(measuring_tank<WATER_LEVEL_SENSOR)
				{
					read_SENSORS();
				}
			}
			else
			{
				BUZZER_off();
				pump_ON();
			}

		}
		else
		{
			lcd_WETSOIL();
			BUZZER_off();
			pump_OFF();
			if(measuring_tank<WATER_LEVEL_SENSOR)
			{
				BUZZER_on();
				pump_OFF();
				while(measuring_tank<WATER_LEVEL_SENSOR)
				{
					read_SENSORS();
				}
			}
		}

	}
}


