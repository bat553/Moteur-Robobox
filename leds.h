/***********************/
/* MAE MOTEUR */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#ifndef _LED_H_ 
#define _LED_H_ 

enum
{
 ETAT_LED_OFF,
 ETAT_LED_ON,
 ETAT_LED_BLINK
};


void LED1_Setup(void);
void LED1_MAE(void);
void LED1_SetLed_ON(void);
void LED1_SetLed_OFF(void);
void LED1_SetLed_BLINK(int iPeriod);
void LED1_Toggle(void);



void LED2_Setup(void);
void LED2_MAE(void);
void LED2_SetLed_ON(void);
void LED2_SetLed_OFF(void);
void LED2_Toggle(void);

#define LED1_PIN 5
#define LED2_PIN 11

#endif
