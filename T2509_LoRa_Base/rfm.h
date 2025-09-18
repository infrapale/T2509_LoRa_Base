#ifndef __RFM_H__
#define __RFM_H__
#include "Arduino.h"
#include <RH_RF95.h>
#include "main.h"
#include "atask.h"
#include "parser.h"

#define NBR_OF_MODEM_CONF   5


typedef enum
{
    DEFAULT_ADDRESS = 0,
    CLIENT_ADDRESS  = 1,
    SERVER_ADDRESS  = 2
} addr_type_et;

typedef enum
{
    REPLY_UNDEFINED = 0,
    REPLY_RECEIVED,
    REPLY_REQUEST,
    REPLY_FAILED,
    REPLY_ACK,
    REPLY_NBR_OF
} reply_et;

typedef struct
{
  char      start;
  char      cmnd[CMD_TAG_LEN];
  uint8_t   from;
  uint8_t   target;
  uint8_t   radio;
  uint8_t   power;
  int16_t   rssi;
  uint8_t   sf;
  uint16_t  remote_nbr;
  uint16_t  base_nbr;
  char      end;
} field_st;


typedef struct
{
  uint8_t         len;
  field_st        field;
  msg_status_et   status;
  bool            avail;
} msg_st;

typedef struct
{
    bool get_rssi;
    bool get_role;
    bool get_msg;
} sub_task_st;

typedef struct 
{
    msg_st          tx_msg;
    msg_st          rx_msg;
    uint8_t         node_addr;
    node_role_et    node_role;
    int             rssi;
    int8_t          power;
    float           frequency;
    RH_RF95::ModemConfigChoice  modem_conf;
    uint8_t         sf;
    uint16_t        client_cntr;
    uint16_t        server_cntr;
    uint8_t         tindx;
    atask_st        *taskp;
    uint32_t        tatio;  
    uint8_t         send_msg[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t         rec_msg[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t         send_msg_len;
    uint8_t         rec_msg_len;
    reply_et        reply_status;
    sub_task_st     sub_task;
} rfm_ctrl_st;

typedef struct
{
    uint16_t send_cntr;
    uint16_t rec_cntr;
} client_msg_st;

void rfm_initialize(node_role_et node_role);

void rfm_task_initilaize(void);

void rfm_reset(void);

void rfm_set_power(int8_t pwr);

void rfm_set_frequency(float freq);

void rfm_set_modem_conf(int8_t modem_conf_indx);

void rfm_set_sf(uint8_t sf);

void rfm_send_str(char *msg);

void rfm_task(void);




#endif