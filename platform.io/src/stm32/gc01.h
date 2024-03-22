/*
 * Rad Pro
 * FNIRSI GC-01 specifics
 *
 * (C) 2022-2024 Gissio
 *
 * License: MIT
 */

#include "stm32.h"

#define SYSCLK_FREQUENCY 72000000
#define AHB_FREQUENCY SYSCLK_FREQUENCY
#define APB1_FREQUENCY (SYSCLK_FREQUENCY / 2)
#define APB2_FREQUENCY SYSCLK_FREQUENCY
#define TIM_FREQUENCY SYSCLK_FREQUENCY
#define LSE_FREQUENCY 32768
#define LSI_FREQUENCY 40000

#if defined(CH32)
#define FLASH_SIZE 0x10000
#elif defined(APM32)
#define FLASH_SIZE 0x20000
#endif
#define FIRMWARE_BASE 0x08004000
#if defined(CH32)
#define FLASH_SIZE 0x10000
#define FIRMWARE_SIZE 0xa800
#elif defined(APM32)
#define FIRMWARE_SIZE 0xc000
#endif

#define PWR_EN_PORT GPIOA
#define PWR_EN_PIN 2
#define PWR_BAT_PORT GPIOA
#define PWR_BAT_PIN 0
#define PWR_BAT_CHANNEL 0
#define PWR_BAT_SCALE_FACTOR 2.0F
#define PWR_CHRG_PORT GPIOA
#define PWR_CHRG_PIN 4
#define PWR_CHRG_PULLUP

#define TUBE_HV_PORT GPIOA
#define TUBE_HV_PIN 3
#define TUBE_HV_TIMER TIM2
#define TUBE_HV_TIMER_CHANNEL TIM_CH4
#define TUBE_DET_PORT GPIOC
#define TUBE_DET_PIN 10
#define TUBE_DET_PULLUP
#define TUBE_DET_IRQ EXTI15_10_IRQn
#define TUBE_DET_IRQ_HANDLER EXTI15_10_IRQHandler
#define TUBE_DET_TIMER_MASTER TIM3
#define TUBE_DET_TIMER_SLAVE TIM4
#define TUBE_DET_TIMER_TRIGGER_CONNECTION 2

#define KEY_LEFT_PORT GPIOC
#define KEY_LEFT_PIN 3
#define KEY_RIGHT_PORT GPIOC
#define KEY_RIGHT_PIN 1
#define KEY_UP_PORT GPIOC
#define KEY_UP_PIN 0
#define KEY_DOWN_PORT GPIOC
#define KEY_DOWN_PIN 2
#define KEY_SELECT_PORT GPIOA
#define KEY_SELECT_PIN 1

#define BUZZ_PORT GPIOA
#define BUZZ_PIN 8
#define BUZZ_TIMER TIM1
#define BUZZ_TIMER_CHANNEL TIM_CH1
#define BUZZ_TIMER_FREQUENCY 2000
#define BUZZ_TIMER_PERIOD (TIM_FREQUENCY / BUZZ_TIMER_FREQUENCY)

#define DISPLAY_RESX_PORT GPIOC
#define DISPLAY_RESX_PIN 5
#define DISPLAY_RDX_PORT GPIOC
#define DISPLAY_RDX_PIN 6
#define DISPLAY_WRX_PORT GPIOC
#define DISPLAY_WRX_PIN 7
#define DISPLAY_DCX_PORT GPIOC
#define DISPLAY_DCX_PIN 8
#define DISPLAY_CSX_PORT GPIOC
#define DISPLAY_CSX_PIN 9
#define DISPLAY_DATA_PORT GPIOB
#define DISPLAY_BACKLIGHT_PORT GPIOA
#define DISPLAY_BACKLIGHT_PIN 10
#define DISPLAY_BACKLIGHT_ACTIVE_LOW
#define DISPLAY_BACKLIGHT_TIMER TIM1
#define DISPLAY_BACKLIGHT_TIMER_CHANNEL TIM_CH3
#define DISPLAY_BACKLIGHT_TIMER_FREQUENCY BUZZ_TIMER_FREQUENCY
#define DISPLAY_BACKLIGHT_TIMER_PERIOD BUZZ_TIMER_PERIOD

#define PULSELED_PORT GPIOA
#define PULSELED_PIN 15

#define VIBRATOR_PORT GPIOA
#define VIBRATOR_PIN 9

#define USB_INTERFACE USB
#define USB_DM_PORT GPIOA
#define USB_DM_PIN 11
#define USB_DP_PORT GPIOA
#define USB_DP_PIN 12
#define USB_IRQ USB_LP_IRQn
#define USB_IRQ_HANDLER USB_LP_IRQHandler
