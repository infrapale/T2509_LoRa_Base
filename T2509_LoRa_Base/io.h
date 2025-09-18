#ifndef __IO_H__ 
#define __IO_H__
#include <Arduino.h>
//#include "main.h"

#define BOARD_T2504_PICO_RFM95_80x70    1
#define BOARD_PROTO_PICO_RFM95          2
#define BOARD BOARD_T2504_PICO_RFM95_80x70 

#define PIN_WIRE_SDA        (12u)
#define PIN_WIRE_SCL        (13u)
#define PIN_UART0_TX        (0u)
#define PIN_UART0_RX        (1u)
#define PIN_UART1_TX        (8u)
#define PIN_UART1_RX        (9u)


#if BOARD == BOARD_T2504_PICO_RFM95_80x70
#define PIN_RFM_MOSI        (19u)
#define PIN_RFM_MISO        (16u)
#define PIN_RFM_SCK         (18u)
#define PIN_RFM_CS          (17u)
#define PIN_RFM_IRQ         (21u)
#define PIN_RFM_RESET       (20u)

#elif BOARD == BOARD_PROTO_PICO_RFM95
#define PIN_RFM_MOSI        (19u)
#define PIN_RFM_MISO        (16u)
#define PIN_RFM_SCK         (18u)
#define PIN_RFM_CS          (10u)
#define PIN_RFM_IRQ         (21u)
#define PIN_RFM_RESET       (11u)
#else
#error No board was defined
#endif

#define PIN_SW1		          (15u)
#define PIN_SW2		          (14u)
#define PIN_SW3		          (13u)
#define PIN_SW4             (12u)

#define PIN_LED_RED         (2u)
#define PIN_LED_GREEN       (3u)
#define PIN_LED_BLUE        (22u)



typedef enum
{
  COLOR_RED = 0,
  COLOR_GREEN,
  COLOR_BLUE,
  COLOR_NBR_OF
} color_et;

typedef enum
{
  BLINK_OFF = 0,
  BLINK_ON,
  BLINK_SHORT_FLASH,
  BLINK_FLASH,
  BLINK_FAST_FLASH,
  BLINK_SLOW_BLINK,
  BLINK_BLINK,
  BLINK_FAST_BLINK,
  BLINK_CLIENT,
  BLINK_RELIABLE_CLIENT,
  BLINK_SERVER,
  BLINK_RELIABLE_SERVER,
  BLINK_NBR_OF
} blink_et;

void io_initialize(void);

void io_task_initialize(void);

uint8_t io_get_switch_bm(void);

void io_blink(uint8_t color, blink_et bindx);

void io_task(void);

#endif