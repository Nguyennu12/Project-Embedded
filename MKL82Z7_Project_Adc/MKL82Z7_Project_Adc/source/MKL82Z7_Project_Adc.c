/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    MKL82Z7_Project_Adc.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL82Z7.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

#define ADC0_GROUP_0          0
#define ADC0_CHANNEL_8        8

/* Define the init structure for the output pin*/
gpio_pin_config_t pin_config_out = {
	kGPIO_DigitalOutput,
	0,
};
gpio_pin_config_t pin_config_in = {
	kGPIO_DigitalInput,
	0,
};

void delayms(void){
	uint32_t count;

	for(count = 0; count < 800000; count++);
}
void initGPIO(void) {
	/* Init Pin to control LED */
	GPIO_PinInit(GPIOC, 0, &pin_config_out);
	GPIO_PinInit(GPIOC, 1, &pin_config_out);
	GPIO_PinInit(GPIOC, 2, &pin_config_out);

	GPIO_PinInit(GPIOA, 4, &pin_config_in);


	/* All LED will be turned off */
	GPIO_PinWrite(GPIOC, 0, 1);
	GPIO_PinWrite(GPIOC, 1, 1);
	GPIO_PinWrite(GPIOC, 2, 1);
}
void PORTA_IRQHandler(void)
{
	/* Turn on red led */
	GPIO_PinWrite(GPIOC, 0, 1);
	GPIO_PinWrite(GPIOC, 1, 0);
	GPIO_PinWrite(GPIOC, 2, 1);

	delayms();

	/* Clear flag */
	GPIO_PortClearInterruptFlags(GPIOA, 1U << 4);
}
int main(void) {

//	adc16_config_t adc16ConfigStruct;
//	adc16_channel_config_t adc16ChannelConfigStruct;
//	uint32_t adcResult;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    /* Init LED */
    initGPIO();
    PORT_SetPinInterruptConfig(PORTA, 4, kPORT_InterruptFallingEdge);
    EnableIRQ(17);
    while(1)
	{
		GPIO_PinWrite(GPIOC, 0, 1);
		GPIO_PinWrite(GPIOC, 1, 1);
		GPIO_PinWrite(GPIOC, 2, 1);
	}

//
//	while(1)
//	{
//		ADC16_SetChannelConfig(ADC0, ADC0_GROUP_0, &adc16ChannelConfigStruct);
//		while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(ADC0, ADC0_GROUP_0)));
//		adcResult = ADC16_GetChannelConversionValue(ADC0, ADC0_GROUP_0);
//		if ((float)(adcResult * 3.3 / 4096) > 1)
//		{
//			GPIO_PinWrite(GPIOC, 0, 1);
//			GPIO_PinWrite(GPIOC, 1, 1);
//			GPIO_PinWrite(GPIOC, 2, 0);
//		}
//		if ((float)(adcResult * 3.3 / 4096) > 2)
//		{
//			GPIO_PinWrite(GPIOC, 0, 1);
//			GPIO_PinWrite(GPIOC, 1, 0);
//			GPIO_PinWrite(GPIOC, 2, 1);
//		}
//		if ((float)(adcResult * 3.3 / 4096) > 3)
//		{
//			GPIO_PinWrite(GPIOC, 0, 0);
//			GPIO_PinWrite(GPIOC, 1, 1);
//			GPIO_PinWrite(GPIOC, 2, 1);
//		}
//	}

    return 0 ;
}
