/***********************/
/* MAE DEBOUNCE */
/***********************/
/* Swano Lab - 2017 */
/***********************/

#include "boutons.h"

int BP2;

int iBP2_DebounceCounter;
int iBP2_EtatDebounce;

void BP2_Etat_Debounce_Relache(void)
{
  BP2 = digitalRead(BP2_PIN);
  if (BP2 == HIGH)
  {
    iBP2_EtatDebounce = ETAT_DEBOUNCING;
  }    
}

void BP2_Etat_Debounce_Debouncing(void)
{
  iBP2_DebounceCounter++;
  if ( iBP2_DebounceCounter == DEBOUNCE_TIME )
  {
    iBP2_EtatDebounce = ETAT_APPUYE;
    iBP2_DebounceCounter = 0;
  }
}
void BP2_Etat_Debounce_Appuye(void)
{
  BP2 = digitalRead(BP2_PIN);
  if (BP2 == LOW)
  {
    iBP2_EtatDebounce = ETAT_RELACHE;
  }    
}

bool BP2_BpEstIlAppuye(void)
{
  return (iBP2_EtatDebounce == ETAT_APPUYE);
}

void BP2_MAE_Setup(void)
{
    pinMode(BP2_PIN, INPUT);

    BP2 = LOW;
    iBP2_DebounceCounter=0;
    iBP2_EtatDebounce = ETAT_RELACHE;
    
    
}

void BP2_MAE(void)
{
  if (iBP2_EtatDebounce == ETAT_RELACHE)
  {
    BP2_Etat_Debounce_Relache();
  }
  
  if (iBP2_EtatDebounce == ETAT_DEBOUNCING)
  {
    BP2_Etat_Debounce_Debouncing();
  }
  
  if (iBP2_EtatDebounce == ETAT_APPUYE)
  {
    BP2_Etat_Debounce_Appuye();
  }
  
}

