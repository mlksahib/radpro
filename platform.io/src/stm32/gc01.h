/*
 * Rad Pro
 * FNIRSI GC-01 pin definitions
 *
 * (C) 2022-2023 Gissio
 *
 * License: MIT
 */

#define PWR_EN_PORT GPIOB
#define PWR_EN_PIN GPIO10
#define PWR_BAT_PORT GPIOA
#define PWR_BAT_PIN GPIO4
#define PWR_BAT_CHANNEL 4
#define PWR_BAT_BATTERY_SCALE_FACTOR
#define PWR_CHRG_PORT GPIOA
#define PWR_CHRG_PIN GPIO5

#define TUBE_HV_PORT GPIOB
#define TUBE_HV_PIN GPIO4
#define TUBE_HV_PORT_SPEED GPIO_OSPEED_HIGH
#define TUBE_HV_TIMER_RCC RCC_TIM3
#define TUBE_HV_TIMER TIM3
#define TUBE_DET_PORT GPIOA
#define TUBE_DET_PIN GPIO6
#define TUBE_DET2_PORT GPIOA
#define TUBE_DET2_PIN GPIO1
#define TUBE_DET_EXTI EXTI6
#define TUBE_DET_EXTI_IRQ NVIC_EXTI9_5_IRQ
#define TUBE_DET_IRQ_HANDLER exti9_5_isr
#define TUBE_DET_TIMER_RCC RCC_TIM1
#define TUBE_DET_TIMER TIM1
#define TUBE_DET_TIMER_HIGH_RCC RCC_TIM2
#define TUBE_DET_TIMER_HIGH TIM2

#define KEY_POWER_PORT GPIOB
#define KEY_POWER_PIN GPIO11
#define KEY_ENTER_PORT GPIOB
#define KEY_ENTER_PIN GPIO1
#define KEY_BACK_PORT GPIOB
#define KEY_BACK_PIN GPIO2
#define KEY_UP_PORT GPIOA
#define KEY_UP_PIN GPIO7
#define KEY_DOWN_PORT GPIOB
#define KEY_DOWN_PIN GPIO0

#define LCD_PORT_SPEED GPIO_OSPEED_HIGH
#define LCD_RESET_PORT GPIOB
#define LCD_RESET_PIN GPIO12
#define LCD_EN_PORT GPIOB
#define LCD_EN_PIN GPIO15
#define LCD_RS_PORT GPIOB
#define LCD_RS_PIN GPIO13
#define LCD_RW_PORT GPIOB
#define LCD_RW_PIN GPIO14
#define LCD_D0_PORT GPIOA
#define LCD_D0_PIN GPIO8
#define LCD_D1_PORT GPIOA
#define LCD_D1_PIN GPIO9
#define LCD_D2_PORT GPIOA
#define LCD_D2_PIN GPIO10
#define LCD_D3_PORT GPIOA
#define LCD_D3_PIN GPIO11
#define LCD_D4_PORT GPIOA
#define LCD_D4_PIN GPIO12
#define LCD_D5_PORT GPIOB
#define LCD_D5_PIN GPIO8
#define LCD_D6_PORT GPIOB
#define LCD_D6_PIN GPIO9
#define LCD_D7_PORT GPIOA
#define LCD_D7_PIN GPIO15
#define LCD_BACKLIGHT_PORT GPIOB
#define LCD_BACKLIGHT_PIN GPIO3

#define BUZZ_PORT GPIOB
#define BUZZ_PIN GPIO5

#define M_VIB_PORT GPIOB
#define M_VIB_PIN GPIO6

#define USART_TX_PORT GPIOA
#define USART_TX_PIN GPIO2
#define USART_RX_PORT GPIOA
#define USART_RX_PIN GPIO3
#define USART_RCC RCC_USART2
#define USART_INTERFACE USART2
#define USART_IRQ NVIC_USART2_IRQ
#define USART_IRQ_HANDLER usart2_isr