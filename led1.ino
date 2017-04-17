/***********************/
/* MAE LED */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#include "leds.h"

int LED1_iEtatEnCours;
int LED1_iCompteurLed;
int LED1_iPeriodTarget;
bool LED1_bPinState;

void LED1_Setup(void)
{
  digitalWrite(LED1_PIN, LOW);
  pinMode(LED1_PIN, OUTPUT);
  LED1_iEtatEnCours = ETAT_LED_OFF;
  LED1_bPinState = LOW;
  LED1_iCompteurLed = 0;
  LED1_iPeriodTarget = 0;
}

void LED1_Etat_ON(void)
{
  digitalWrite(LED1_PIN, HIGH);
  LED1_bPinState = HIGH;
}

void LED1_Etat_OFF(void)
{
  digitalWrite(LED1_PIN, LOW);
  LED1_bPinState = LOW;
}

void LED1_Etat_Blink(void)
{

  LED1_iCompteurLed--;
  if ( LED1_iCompteurLed == 0)
  {
    LED1_Toggle();
    LED1_iCompteurLed = LED1_iPeriodTarget;
  }
}

void LED1_Toggle(void)
{
  if ( LED1_bPinState == LOW)
  {
    digitalWrite(LED1_PIN, HIGH);
    LED1_bPinState = HIGH;
  }
  else
  {
    if ( LED1_bPinState == HIGH)
    {
      digitalWrite(LED1_PIN, LOW);
      LED1_bPinState = LOW;
    }
  }
}

void LED1_SetLed_ON(void)
{
  LED1_iEtatEnCours = ETAT_LED_ON;
}


void LED1_SetLed_OFF(void)
{
  LED1_iEtatEnCours = ETAT_LED_OFF;

}

void LED1_SetLed_BLINK(int iPeriod)
{
  if ( LED1_iEtatEnCours != ETAT_LED_BLINK)
  {
    LED1_iCompteurLed = iPeriod;
    LED1_iPeriodTarget = iPeriod;

    LED1_Toggle();

    LED1_iEtatEnCours = ETAT_LED_BLINK;
  }
}

void LED1_MAE(void)
{
  if (LED1_iEtatEnCours == ETAT_LED_OFF)
  {
    LED1_Etat_OFF();
  }
  if (LED1_iEtatEnCours == ETAT_LED_ON)
  {
    LED1_Etat_ON();
  }
  if (LED1_iEtatEnCours == ETAT_LED_BLINK)
  {
    LED1_Etat_Blink();
  }

}
