/*
 * Copyright 2018 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.1
processor: MKE16Z64xxx4
package_id: MKE16Z64VLF4
mcu_data: ksdk2_0
processor_version: 0.0.0
board: FRDM-KE16Z
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);


	PORT_SetPinMux(PORTA, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTA, 3, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 4, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, 5, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTD, 3, kPORT_MuxAsGpio);


	PORT_SetPinMux(PORTD, 7, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 1, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 0, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 2, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, 8, kPORT_MuxAsGpio);

	PORT_SetPinMux(PORTD, 0, kPORT_MuxAlt2);
	PORT_SetPinMux(PORTC, 0, kPORT_MuxAlt2);


}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOSCPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '11', peripheral: SCG, signal: EXTAL0, pin_signal: EXTAL/PTB7/LPI2C0_SCL}
  - {pin_num: '12', peripheral: SCG, signal: XTAL0, pin_signal: XTAL/PTB6/LPI2C0_SDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitOSCPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitOSCPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortB);

    /* PORTB6 (pin 12) is configured as XTAL */
    PORT_SetPinMux(BOARD_XTAL_PORT, BOARD_XTAL_PIN, kPORT_PinDisabledOrAnalog);

    /* PORTB7 (pin 11) is configured as EXTAL */
    PORT_SetPinMux(BOARD_EXTAL_PORT, BOARD_EXTAL_PIN, kPORT_PinDisabledOrAnalog);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTOUCHPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '5', peripheral: TSI, signal: 'CH, 0', pin_signal: TSI0_CH0/PTE5/TCLK2/CAN0_TX/EWM_IN, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable, digital_filter: disable}
  - {pin_num: '6', peripheral: TSI, signal: 'CH, 1', pin_signal: TSI0_CH1/PTE4/BUSOUT/CAN0_RX/EWM_OUT_b, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitTOUCHPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitTOUCHPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortE);
    /* Configure digital filter */
    PORT_EnablePinsDigitalFilter(
        /* Digital filter is configured on port E */
        PORTE,
        /* Digital filter is configured for PORTE0 */
        PORT_DFER_DFE_5_MASK,
        /* Disable digital filter */
        false);

    const port_pin_config_t TSI_ELECTRODE2 = {/* Internal pull-up/down resistor is disabled */
                                              kPORT_PullDisable,
                                              /* Passive filter is disabled */
                                              kPORT_PassiveFilterDisable,
                                              /* Low drive strength is configured */
                                              kPORT_LowDriveStrength,
                                              /* Pin is configured as TSI0_CH1 */
                                              kPORT_PinDisabledOrAnalog,
                                              /* Pin Control Register fields [15:0] are not locked */
                                              kPORT_UnlockRegister};
    /* PORTE4 (pin 6) is configured as TSI0_CH1 */
    PORT_SetPinConfig(BOARD_TSI_ELECTRODE2_PORT, BOARD_TSI_ELECTRODE2_PIN, &TSI_ELECTRODE2);

    const port_pin_config_t TSI_ELECTRODE1 = {/* Internal pull-up/down resistor is disabled */
                                              kPORT_PullDisable,
                                              /* Passive filter is disabled */
                                              kPORT_PassiveFilterDisable,
                                              /* Low drive strength is configured */
                                              kPORT_LowDriveStrength,
                                              /* Pin is configured as TSI0_CH0 */
                                              kPORT_PinDisabledOrAnalog,
                                              /* Pin Control Register fields [15:0] are not locked */
                                              kPORT_UnlockRegister};
    /* PORTE5 (pin 5) is configured as TSI0_CH0 */
    PORT_SetPinConfig(BOARD_TSI_ELECTRODE1_PORT, BOARD_TSI_ELECTRODE1_PIN, &TSI_ELECTRODE1);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONSPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '33', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/NMI_b, direction: INPUT, slew_rate: slow, open_drain: disable, drive_strength: low, pull_select: down,
    pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '34', peripheral: GPIOD, signal: 'GPIO, 2', pin_signal: PTD2, direction: INPUT, slew_rate: slow, open_drain: disable, drive_strength: low, pull_select: down,
    pull_enable: disable, passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONSPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBUTTONSPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortD);

    gpio_pin_config_t SW3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD2 (pin 34)  */
    GPIO_PinInit(BOARD_SW3_GPIO, BOARD_SW3_PIN, &SW3_config);

    gpio_pin_config_t SW2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD3 (pin 33)  */
    GPIO_PinInit(BOARD_SW2_GPIO, BOARD_SW2_PIN, &SW2_config);

    const port_pin_config_t SW3 = {/* Internal pull-up/down resistor is disabled */
                                   kPORT_PullDisable,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTD2 */
                                   kPORT_MuxAsGpio,
                                   /* Pin Control Register fields [15:0] are not locked */
                                   kPORT_UnlockRegister};
    /* PORTD2 (pin 34) is configured as PTD2 */
    PORT_SetPinConfig(BOARD_SW3_PORT, BOARD_SW3_PIN, &SW3);

    const port_pin_config_t SW2 = {/* Internal pull-up/down resistor is disabled */
                                   kPORT_PullDisable,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTD3 */
                                   kPORT_MuxAsGpio,
                                   /* Pin Control Register fields [15:0] are not locked */
                                   kPORT_UnlockRegister};
    /* PORTD3 (pin 33) is configured as PTD3 */
    PORT_SetPinConfig(BOARD_SW2_PORT, BOARD_SW2_PIN, &SW2);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTHERMISTORPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '28', peripheral: ADC0, signal: 'SE, 3', pin_signal: ADC0_SE3/PTA7/FTM0_FLT2/LPSPI0_PCS3/RTC_CLKIN/LPUART1_RTS, drive_strength: low, pull_select: down,
    pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '29', peripheral: ADC0, signal: 'SE, 2', pin_signal: ADC0_SE2/PTA6/FTM0_FLT1/LPUART1_CTS, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitTHERMISTORPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitTHERMISTORPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortA);

    const port_pin_config_t THER_B = {/* Internal pull-up/down resistor is disabled */
                                      kPORT_PullDisable,
                                      /* Passive filter is disabled */
                                      kPORT_PassiveFilterDisable,
                                      /* Low drive strength is configured */
                                      kPORT_LowDriveStrength,
                                      /* Pin is configured as ADC0_SE2 */
                                      kPORT_PinDisabledOrAnalog,
                                      /* Pin Control Register fields [15:0] are not locked */
                                      kPORT_UnlockRegister};
    /* PORTA6 (pin 29) is configured as ADC0_SE2 */
    PORT_SetPinConfig(BOARD_THER_B_PORT, BOARD_THER_B_PIN, &THER_B);

    const port_pin_config_t THER_A = {/* Internal pull-up/down resistor is disabled */
                                      kPORT_PullDisable,
                                      /* Passive filter is disabled */
                                      kPORT_PassiveFilterDisable,
                                      /* Low drive strength is configured */
                                      kPORT_LowDriveStrength,
                                      /* Pin is configured as ADC0_SE3 */
                                      kPORT_PinDisabledOrAnalog,
                                      /* Pin Control Register fields [15:0] are not locked */
                                      kPORT_UnlockRegister};
    /* PORTA7 (pin 28) is configured as ADC0_SE3 */
    PORT_SetPinConfig(BOARD_THER_A_PORT, BOARD_THER_A_PIN, &THER_A);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitACCELPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '35', peripheral: LPI2C0, signal: SCL, pin_signal: PTA3/LPI2C0_SCL/EWM_IN/LPUART0_TX, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable, digital_filter: disable}
  - {pin_num: '36', peripheral: LPI2C0, signal: SDA, pin_signal: PTA2/LPI2C0_SDA/EWM_OUT_b/LPUART0_RX, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable, digital_filter: disable}
  - {pin_num: '32', peripheral: GPIOD, signal: 'GPIO, 4', pin_signal: PTD4/FTM0_FLT3, direction: INPUT, gpio_interrupt: kPORT_InterruptOrDMADisabled, drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '41', peripheral: GPIOE, signal: 'GPIO, 6', pin_signal: PTE6/LPSPI0_PCS2/LPUART1_RTS, direction: OUTPUT, drive_strength: low, pull_select: down, pull_enable: disable,
    passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitACCELPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitACCELPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t ACCEL_INT_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD4 (pin 32)  */
    GPIO_PinInit(BOARD_ACCEL_INT_GPIO, BOARD_ACCEL_INT_PIN, &ACCEL_INT_config);

    gpio_pin_config_t ACCEL_RST_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE6 (pin 41)  */
    GPIO_PinInit(BOARD_ACCEL_RST_GPIO, BOARD_ACCEL_RST_PIN, &ACCEL_RST_config);

    const port_pin_config_t ACCEL_SDA = {/* Internal pull-up/down resistor is disabled */
                                         kPORT_PullDisable,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as LPI2C0_SDA */
                                         kPORT_MuxAlt3,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTA2 (pin 36) is configured as LPI2C0_SDA */
    PORT_SetPinConfig(BOARD_ACCEL_SDA_PORT, BOARD_ACCEL_SDA_PIN, &ACCEL_SDA);

    const port_pin_config_t ACCEL_SCL = {/* Internal pull-up/down resistor is disabled */
                                         kPORT_PullDisable,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as LPI2C0_SCL */
                                         kPORT_MuxAlt3,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTA3 (pin 35) is configured as LPI2C0_SCL */
    PORT_SetPinConfig(BOARD_ACCEL_SCL_PORT, BOARD_ACCEL_SCL_PIN, &ACCEL_SCL);

    const port_pin_config_t ACCEL_INT = {/* Internal pull-up/down resistor is disabled */
                                         kPORT_PullDisable,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as PTD4 */
                                         kPORT_MuxAsGpio,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTD4 (pin 32) is configured as PTD4 */
    PORT_SetPinConfig(BOARD_ACCEL_INT_PORT, BOARD_ACCEL_INT_PIN, &ACCEL_INT);

    /* Interrupt configuration on PORTD4 (pin 32): Interrupt/DMA request is disabled */
    PORT_SetPinInterruptConfig(BOARD_ACCEL_INT_PORT, BOARD_ACCEL_INT_PIN, kPORT_InterruptOrDMADisabled);
    /* Configure digital filter */
    PORT_EnablePinsDigitalFilter(
        /* Digital filter is configured on port E */
        PORTE,
        /* Digital filter is configured for PORTE0 */
        PORT_DFER_DFE_6_MASK,
        /* Disable digital filter */
        false);

    const port_pin_config_t ACCEL_RST = {/* Internal pull-up/down resistor is disabled */
                                         kPORT_PullDisable,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as PTE6 */
                                         kPORT_MuxAsGpio,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTE6 (pin 41) is configured as PTE6 */
    PORT_SetPinConfig(BOARD_ACCEL_RST_PORT, BOARD_ACCEL_RST_PIN, &ACCEL_RST);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '26', peripheral: LPUART0, signal: TX, pin_signal: ADC0_SE5/PTB1/LPUART0_TX/LPSPI0_SOUT/TCLK0, drive_strength: low, pull_select: up, pull_enable: enable,
    passive_filter: disable, digital_filter: disable}
  - {pin_num: '27', peripheral: LPUART0, signal: RX, pin_signal: ADC0_SE4/PTB0/LPUART0_RX/LPSPI0_PCS0/LPTMR0_ALT3/PWT_IN3, drive_strength: low, pull_select: up, pull_enable: enable,
    passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortB);

    const port_pin_config_t DEBUG_UART_RX = {/* Internal pull-up resistor is enabled */
                                             kPORT_PullUp,
                                             /* Passive filter is disabled */
                                             kPORT_PassiveFilterDisable,
                                             /* Low drive strength is configured */
                                             kPORT_LowDriveStrength,
                                             /* Pin is configured as LPUART0_RX */
                                             kPORT_MuxAlt2,
                                             /* Pin Control Register fields [15:0] are not locked */
                                             kPORT_UnlockRegister};
    /* PORTB0 (pin 27) is configured as LPUART0_RX */
    PORT_SetPinConfig(BOARD_DEBUG_UART_RX_PORT, BOARD_DEBUG_UART_RX_PIN, &DEBUG_UART_RX);

    const port_pin_config_t DEBUG_UART_TX = {/* Internal pull-up resistor is enabled */
                                             kPORT_PullUp,
                                             /* Passive filter is disabled */
                                             kPORT_PassiveFilterDisable,
                                             /* Low drive strength is configured */
                                             kPORT_LowDriveStrength,
                                             /* Pin is configured as LPUART0_TX */
                                             kPORT_MuxAlt2,
                                             /* Pin Control Register fields [15:0] are not locked */
                                             kPORT_UnlockRegister};
    /* PORTB1 (pin 26) is configured as LPUART0_TX */
    PORT_SetPinConfig(BOARD_DEBUG_UART_TX_PORT, BOARD_DEBUG_UART_TX_PIN, &DEBUG_UART_TX);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '1', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: TSI0_CH5/PTD1/FTM0_CH3/TRGMUX_OUT2, direction: OUTPUT, gpio_init_state: 'true', drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '15', peripheral: GPIOB, signal: 'GPIO, 5', pin_signal: TSI0_CH9/PTB5/FTM0_CH5/LPSPI0_PCS1/TRGMUX_IN0, direction: OUTPUT, gpio_init_state: 'true', drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '16', peripheral: GPIOB, signal: 'GPIO, 4', pin_signal: TSI0_CH8/PTB4/FTM0_CH4/LPSPI0_SOUT/TRGMUX_IN1, direction: OUTPUT, gpio_init_state: 'true', drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLEDsPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortD);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB4 (pin 16)  */
    GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_PIN, &LED_GREEN_config);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB5 (pin 15)  */
    GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_PIN, &LED_RED_config);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD1 (pin 1)  */
    GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_PIN, &LED_BLUE_config);

    const port_pin_config_t LED_GREEN = {/* Internal pull-up/down resistor is disabled */
                                         kPORT_PullDisable,
                                         /* Passive filter is disabled */
                                         kPORT_PassiveFilterDisable,
                                         /* Low drive strength is configured */
                                         kPORT_LowDriveStrength,
                                         /* Pin is configured as PTB4 */
                                         kPORT_MuxAsGpio,
                                         /* Pin Control Register fields [15:0] are not locked */
                                         kPORT_UnlockRegister};
    /* PORTB4 (pin 16) is configured as PTB4 */
    PORT_SetPinConfig(BOARD_LED_GREEN_PORT, BOARD_LED_GREEN_PIN, &LED_GREEN);

    const port_pin_config_t LED_RED = {/* Internal pull-up/down resistor is disabled */
                                       kPORT_PullDisable,
                                       /* Passive filter is disabled */
                                       kPORT_PassiveFilterDisable,
                                       /* Low drive strength is configured */
                                       kPORT_LowDriveStrength,
                                       /* Pin is configured as PTB5 */
                                       kPORT_MuxAsGpio,
                                       /* Pin Control Register fields [15:0] are not locked */
                                       kPORT_UnlockRegister};
    /* PORTB5 (pin 15) is configured as PTB5 */
    PORT_SetPinConfig(BOARD_LED_RED_PORT, BOARD_LED_RED_PIN, &LED_RED);

    const port_pin_config_t LED_BLUE = {/* Internal pull-up/down resistor is disabled */
                                        kPORT_PullDisable,
                                        /* Passive filter is disabled */
                                        kPORT_PassiveFilterDisable,
                                        /* Low drive strength is configured */
                                        kPORT_LowDriveStrength,
                                        /* Pin is configured as PTD1 */
                                        kPORT_MuxAsGpio,
                                        /* Pin Control Register fields [15:0] are not locked */
                                        kPORT_UnlockRegister};
    /* PORTD1 (pin 1) is configured as PTD1 */
    PORT_SetPinConfig(BOARD_LED_BLUE_PORT, BOARD_LED_BLUE_PIN, &LED_BLUE);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitCANPins:
- options: {callFromInitBoot: 'false', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '39', peripheral: MSCAN, signal: TX, pin_signal: TSI0_CH16/PTC7/LPUART1_TX/CAN0_TX, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable,
    digital_filter: disable}
  - {pin_num: '40', peripheral: MSCAN, signal: RX, pin_signal: TSI0_CH15/PTC6/LPUART1_RX/CAN0_RX, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable,
    digital_filter: disable}
  - {pin_num: '24', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: ADC0_SE7/TSI0_CH21/PTB3/FTM1_CH1/LPSPI0_SIN/FTM1_QD_PHA/TRGMUX_IN2, direction: OUTPUT, drive_strength: low,
    pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitCANPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitCANPins(void)
{
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Clock Gate Control: 0x01u */
    CLOCK_EnableClock(kCLOCK_PortC);

    gpio_pin_config_t CAN_STANDBY_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 24)  */
    GPIO_PinInit(BOARD_CAN_STANDBY_GPIO, BOARD_CAN_STANDBY_PIN, &CAN_STANDBY_config);

    const port_pin_config_t CAN_STANDBY = {/* Internal pull-up/down resistor is disabled */
                                           kPORT_PullDisable,
                                           /* Passive filter is disabled */
                                           kPORT_PassiveFilterDisable,
                                           /* Low drive strength is configured */
                                           kPORT_LowDriveStrength,
                                           /* Pin is configured as PTB3 */
                                           kPORT_MuxAsGpio,
                                           /* Pin Control Register fields [15:0] are not locked */
                                           kPORT_UnlockRegister};
    /* PORTB3 (pin 24) is configured as PTB3 */
    PORT_SetPinConfig(BOARD_CAN_STANDBY_PORT, BOARD_CAN_STANDBY_PIN, &CAN_STANDBY);

    const port_pin_config_t CAN_RX = {/* Internal pull-up/down resistor is disabled */
                                      kPORT_PullDisable,
                                      /* Passive filter is disabled */
                                      kPORT_PassiveFilterDisable,
                                      /* Low drive strength is configured */
                                      kPORT_LowDriveStrength,
                                      /* Pin is configured as CAN0_RX */
                                      kPORT_MuxAlt5,
                                      /* Pin Control Register fields [15:0] are not locked */
                                      kPORT_UnlockRegister};
    /* PORTC6 (pin 40) is configured as CAN0_RX */
    PORT_SetPinConfig(BOARD_CAN_RX_PORT, BOARD_CAN_RX_PIN, &CAN_RX);

    const port_pin_config_t CAN_TX = {/* Internal pull-up/down resistor is disabled */
                                      kPORT_PullDisable,
                                      /* Passive filter is disabled */
                                      kPORT_PassiveFilterDisable,
                                      /* Low drive strength is configured */
                                      kPORT_LowDriveStrength,
                                      /* Pin is configured as CAN0_TX */
                                      kPORT_MuxAlt5,
                                      /* Pin Control Register fields [15:0] are not locked */
                                      kPORT_UnlockRegister};
    /* PORTC7 (pin 39) is configured as CAN0_TX */
    PORT_SetPinConfig(BOARD_CAN_TX_PORT, BOARD_CAN_TX_PIN, &CAN_TX);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
