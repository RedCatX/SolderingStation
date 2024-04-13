/*
 * SolderingStation.c
 *
 * Created: 27.11.2019 21:09:19
 * Author : RedCAT
 */ 

#include "view.h"
#include "timer.h"

int main()
{
    model_init();
    view_init();
    controller_init();
    timer_init();
    view_main_screen();
    
    while (1)
    {
        controller_update();
        view_update();      
    }    
        
	return 0;
}
