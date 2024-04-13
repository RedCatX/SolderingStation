/*
 * controller.c
 *
 * Created: 05.11.2021 22:00:48
 *  Author: RedCAT
 */ 

#include <avr/interrupt.h>
#include <stddef.h>
#include "setup.h"
#include "timer.h"
#include "model.h"
#include "view.h"

#define ENC_PUSH(v) ((v) & 4) 
#define ENC_TURN(v) ((v) & 3)
#define ENCODER_DOWN 8
#define ENCODER_UP   16

void temp_inc();
void temp_dec();
void temp_set();
void temp_set_screen();
void change_beep();
void change_boost();
void iron_tip_prev();
void iron_tip_next();
void iron_tip_select();
void iron_tip_edit();

void encoder_click_timer();

#include "fsm.h"

/*FSM_STATE_TABLE_BEGIN
    FSM_TRANSITION(MainScreen, EncoderClick, MainMenuReturn, &view_main_menu),
    FSM_TRANSITION(MainScreen, EncoderLongClick, MainScreen, &change_boost),
    FSM_TRANSITION(MainScreen, EncoderTurnLeft, TempSet, &temp_set_screen),
    FSM_TRANSITION(MainScreen, EncoderTurnRight, TempSet, &temp_set_screen),
    FSM_TRANSITION(MainMenuReturn, EncoderTurnRight, MainMenuIronTip, &menu_selection_down),
    FSM_TRANSITION(MainMenuReturn, EncoderClick, MainScreen, &view_main_screen),
    FSM_TRANSITION(MainMenuIronTip, EncoderTurnLeft, MainMenuReturn, &menu_selection_up),
    FSM_TRANSITION(MainMenuIronTip, EncoderTurnRight, MainMenuTempSet, &menu_selection_down),
    //FSM_TRANSITION(MainMenuIronTip, EncoderClick, IronTipMenu, NULL),
    FSM_TRANSITION(MainMenuTempSet, EncoderTurnLeft, MainMenuIronTip, &menu_selection_up),
    FSM_TRANSITION(MainMenuTempSet, EncoderTurnRight, MainMenuBoost, &menu_selection_down),
    FSM_TRANSITION(MainMenuTempSet, EncoderClick, TempSet, &temp_set_screen),
    FSM_TRANSITION(MainMenuBoost, EncoderTurnLeft, MainMenuTempSet, &menu_selection_up),
    FSM_TRANSITION(MainMenuBoost, EncoderTurnRight, MainMenuSleep, &menu_selection_down),
    //FSM_TRANSITION(MainMenuBoost, EncoderClick, BoostMenu, NULL),
    FSM_TRANSITION(MainMenuSleep, EncoderTurnLeft, MainMenuBoost, &menu_selection_up),
    FSM_TRANSITION(MainMenuSleep, EncoderTurnRight, MainMenuBeep, &menu_selection_down),
    //FSM_TRANSITION(MainMenuSleep, EncoderClick, SleepMenu, NULL),
    FSM_TRANSITION(MainMenuBeep, EncoderTurnLeft, MainMenuSleep, &menu_selection_up),
    FSM_TRANSITION(MainMenuBeep, EncoderClick, MainMenuBeep, &change_beep),
    FSM_TRANSITION(TempSet, EncoderTurnLeft, TempSet, &temp_dec),
    FSM_TRANSITION(TempSet, EncoderTurnRight, TempSet, &temp_inc),
    FSM_TRANSITION(TempSet, EncoderClick, MainScreen, &temp_set),
    FSM_TRANSITION(IronTipMenu, EncoderTurnLeft, IronTipMenu, &iron_tip_prev),
    FSM_TRANSITION(IronTipMenu, EncoderTurnRight, IronTipMenu, &iron_tip_next),
    FSM_TRANSITION(IronTipMenu, EncoderClick, MainScreen, &iron_tip_select),
    FSM_TRANSITION(IronTipMenu, EncoderLongClick, IronTipMenu, &iron_tip_edit)
FSM_STATE_TABLE_END*/

volatile uint8_t enc = 4;
volatile uint8_t encoder_state = 0;
volatile event_t event = EventNone;
fsm_state_t state = MainScreen;
uint16_t temp_adj;

uint8_t read_encoder()
{
    uint8_t value = 0;
    
    if (ENCODER_PINS & (1 << ENCODER_BUTTON_PIN))
        value |= (1<<2);
    
    if (ENCODER_PINS & (1 << ENCODER_LEFT_PIN))
        value |= (1<<1);

    if (ENCODER_PINS & (1 << ENCODER_RIGHT_PIN))
        value |= (1<<0);

    return value;
}

void controller_init()
{
    cli();
    
    ENCODER_DDR = 0;
    ENCODER_PORT = 0;
    PCICR |= (1 << ENCODER_PCIE);
    ENCODER_PCMSK |= ENCODER_MASK;
    
    sei(); 
}

ISR(PCINT1_vect) 
{
    uint8_t enc_new = read_encoder();
    
    if (enc != enc_new)
    {
        // Encoder turn
        if (/*(ENC_TURN(enc) == 3 && ENC_TURN(enc_new) == 1) ||*/
            (ENC_TURN(enc) == 0 && ENC_TURN(enc_new) == 2))
        {
            event = EncoderTurnRight;
        }
        else if ((ENC_TURN(enc) == 2 && ENC_TURN(enc_new) == 0) /*||
                 (ENC_TURN(enc) == 1 && ENC_TURN(enc_new) == 3)*/)
        {
            event = EncoderTurnLeft;
        }
        // Encoder push
        if (ENC_PUSH(enc) == 4 && ENC_PUSH(enc_new) == 0)
        {
            attach_timer_func(&encoder_click_timer, 1100);
        }
        else if (ENC_PUSH(enc) == 0 && ENC_PUSH(enc_new) == 4)  
        {
            detach_timer_func(&encoder_click_timer);
            event = EncoderClick;
        }   
        enc = enc_new;        
    }
}

void temp_inc()
{
    temp_adj += TEMP_SET_STEP;
    if (temp_adj > TEMP_SET_MAX)
        temp_adj = TEMP_SET_MAX;
    invalidate_screen();
}

void temp_dec()
{
    temp_adj -= TEMP_SET_STEP;
    if (temp_adj < TEMP_SET_MIN)
        temp_adj = TEMP_SET_MIN;
    invalidate_screen();
}

void temp_set()
{
    set_temperature(temp_adj);
    view_main_screen();
}

void temp_set_screen()
{
    temp_adj = get_temperature();
    view_temp_set_screen();
}

void change_beep()
{
    change_signal_state();
    attach_timer_func(&change_signal_state, 1000);
    menu_refresh_selected();
}

void change_boost()
{
    boost_mode();
    invalidate_screen();
}

void iron_tip_prev()
{
    
}

void iron_tip_next()
{
    
}

void iron_tip_select()
{
    
}

void iron_tip_edit()
{
    
}

uint16_t get_temp_adj()
{
    return temp_adj;
}

void encoder_click_timer()
{
    detach_timer_func(&encoder_click_timer);
    enc |= 4;
    event = EncoderLongClick;
}  

void controller_update()
{
    /*uint8_t evt = event;
    uint8_t new = FSM_Table[state][evt].new_state;
 
    if (evt != EventNone && new != StateNone)
    {
        if (FSM_Table[state][evt].worker)
            FSM_Table[state][evt].worker();
            
        state = new;
          
        event = EventNone;
    }*/
}