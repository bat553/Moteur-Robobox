/***********************/
/* MAE LED */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#include "leds.h"

int LED2_iEtatEnCours;
int LED2_iCompteurLed;
int LED2_iPeriodTarget;
bool LED2_bPinState;

void LED2_Setup(void)
{
  digitalWrite(LED2_PIN, LOW);
  pinMode(LED2_PIN, OUTPUT);
  LED2_iEtatEnCours = ETAT_LED_OFF;
  LED2_bPinState = LOW;
  LED2_iCompteurLed = 0;
  LED2_iPeriodTarget = 0;
}

void LED2_Etat_ON(void)
{
  digitalWrite(LED2_PIN, HIGH);
  LED2_bPinState = HIGH;
}

void LED2_Etat_OFF(void)
{
  digitalWrite(LED2_PIN, LOW);
  LED2_bPinState = LOW;
}

void LED2_Etat_Blink(void)
{

  LED2_iCompteurLed--;
  if ( LED2_iCompteurLed == 0)
  {
    LED2_Toggle();
    LED2_iCompteurLed = LED2_iPeriodTarget;
  }
}

void LED2_Toggle(void)
{
  if ( LED2_bPinState == LOW)
  {
    digitalWrite(LED2_PIN, HIGH);
    LED2_bPinState = HIGH;
  }
  else
  {
    if ( LED2_bPinState == HIGH)
    {
      digitalWrite(LED2_PIN, LOW);
      LED2_bPinState = LOW;
    }
  }
}

void LED2_SetLed_ON(void)
{
  LED2_iEtatEnCours = ETAT_LED_ON;
}


void LED2_SetLed_OFF(void)
{
  LED2_iEtatEnCours = ETAT_LED_OFF;

}

void LED2_SetLed_BLINK(int iPeriod)
{
  if ( LED2_iEtatEnCours != ETAT_LED_BLINK)
  {
    LED2_iCompteurLed = iPeriod;
    LED2_iPeriodTarget = iPeriod;

    LED2_Toggle();

    LED2_iEtatEnCours = ETAT_LED_BLINK;
  }
}

void LED2_MAE(void)
{
  if (LED2_iEtatEnCours == ETAT_LED_OFF)
  {
    LED2_Etat_OFF();
  }
  if (LED2_iEtatEnCours == ETAT_LED_ON)
  {
    LED2_Etat_ON();
  }
  if (LED2_iEtatEnCours == ETAT_LED_BLINK)
  {
    LED2_Etat_Blink();
  }

}
