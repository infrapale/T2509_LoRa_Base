#include "hardware/watchdog.h"
#include "rfm.h"
#include "main.h"
#include "io.h"

#define  ACTIVITY_TIMEOUT (30*60000)

typedef struct 
{
    uint32_t activity_timeout;
    bool    wd_is_active;
} boss_st;

extern main_ctrl_st main_ctrl;

boss_st boss = 
{
    .activity_timeout = ACTIVITY_TIMEOUT,
    .wd_is_active = false,
};



void boss_task(void);

//                                  123456789012345   ial  next  state  prev  cntr flag  call backup
atask_st boss_handle          =  {"Boss Task      ", 1000,    0,     0,  255,    0,  1,  boss_task };

void boss_initialize(bool enable_wd)
{
    if(enable_wd){
        boss.wd_is_active = enable_wd;
         watchdog_enable(8000, true);
    }
    boss.activity_timeout = millis() + ACTIVITY_TIMEOUT;
    atask_add_new(&boss_handle);  
}

void boss_activity_event(void)
{
    boss.activity_timeout = millis() + ACTIVITY_TIMEOUT;
}

void boss_task(void)
{
    switch(boss_handle.state)
    {
        case 0:
            boss.activity_timeout = millis() + ACTIVITY_TIMEOUT;
            boss_handle.state = 10;
            break;
        case 10:
            watchdog_update();
            boss_handle.state = 20;
            break;
        case 20:
            if (millis() < boss.activity_timeout) boss_handle.state = 10;
            else {
                Serial.println("Waiting for Restart");
                boss_handle.state = 100;
            }
            break;
        case 100:
            // wait for WD reset
            break;
    }
}
