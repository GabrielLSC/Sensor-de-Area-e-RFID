/*
 * File:   ultrasonic.c
 * Author: 21193444
 *
 * Created on 3 de Agosto de 2022, 10:00
 */


#include <xc.h>
#include "config.h"
#include "ultrasonic.h"

#define TRIGGER PORTAbits.RA0
#define ECHO    PORTAbits.RA1
int distance;

void timer_sets (void)
{
    TMR1 =   0;
    TMR1CS = 0;
    T1CKPS0 = 0;
    T1CKPS1 = 0;
}
void ultrasonic_init (void)
{
    TRISAbits.TRISA0 = 0;
    
    PORTAbits.RA0 = 0;
}

void trigger (void)
{
    TRIGGER = 1;
    __delay_us (10);
    TRIGGER = 0;
}

int calc_distance (void)
{
    TMR1 = 0;
    while (!ECHO)
    {
        TMR1ON = 1;
    }
    while (ECHO)
    {
        TMR1ON = 0;
    }
    distance = TMR1/58.82;
    return (distance);
}

