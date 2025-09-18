#ifndef __MAIN_H__
#define __MAIN_H__

//#define LORA_CLIENT
#define LORA_SERVER

#define LABEL_LEN           12
#define TIME_ZONE_OFFS      3
#define UNIT_LABEL_LEN      10
#define MEASURE_LABEL_LEN   16

#define APP_NAME   "T2509_LoRa_Base"
#define SW_BM_TEST          0b00001000
#define SW_BM_ROLE          0b00000100
#define SW_BM_ADDR_1        0b00000010
#define SW_BM_ADDR_0        0b00000001
#define SW_BM_ADDR          0b00000011
#define DEBUG_PRINT

#define UART_0              Serial
#define DEBUG_UART_BPS      9600
#define INTERCONNECT_UART_BPS      9600

typedef enum
{
    NODE_ROLE_UNDEFINED = 0,
    NODE_ROLE_CLIENT,
    NODE_ROLE_SERVER,
    NODE_ROLE_NBR_OF
} node_role_et;


typedef struct 
{
    uint8_t      node_addr;
    node_role_et node_role;
    bool         test_activated;
    bool         io_initialized;
    uint8_t      serial_reserved;
} main_ctrl_st;




typedef struct date_time
{
    uint16_t  year;
    uint8_t   month;
    uint8_t   day;
    uint8_t   hour;
    uint8_t   minute;
    uint8_t   second;
 } date_time_st;

#endif
