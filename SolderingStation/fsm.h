/*
 * fsm.h
 *
 * Created: 15.03.2024 7:35:10
 *  Author: RedCAT
 */ 


#ifndef FSM_H_
#define FSM_H_

typedef enum State
{
    StateNone = 0,
    MainScreen,
    TempSet,
    MainMenuReturn,
    MainMenuIronTip,
    MainMenuTempSet,
    MainMenuBoost,
    MainMenuSleep,
    MainMenuBeep,
    IronTipMenu,
    BoostMenu,
    SleepMenu,
    StateCount
} fsm_state_t;

typedef enum Event
{
    EventNone = 0,
    EncoderClick,
    EncoderLongClick,
    EncoderTurnLeft,
    EncoderTurnRight,
    EventCount
} event_t;

typedef void (*transition_callback_t)();

struct FSMTransition
{
    fsm_state_t new_state;
    transition_callback_t worker;
};

#define FSM_STATE_TABLE_BEGIN struct FSMTransition FSM_Table[StateCount][EventCount] = {
#define FSM_TRANSITION(cur, event, next, callback) [cur][event] = { next, callback }
#define FSM_STATE_TABLE_END };

#endif /* FSM_H_ */