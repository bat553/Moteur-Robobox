/***********************/
/* MAE DEBOUNCE */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#include "boutons.h"

int iBp1;

int iBP1_DebounceCounter;
int iBP1_EtatDebounce;

void BP1_Etat_Debounce_Relache(void)
{
  iBp1 = digitalRead(BP1_PIN);
  if (iBp1 == HIGH)
  {
    iBP1_EtatDebounce = ETAT_DEBOUNCING;
  }    
}

void BP1_Etat_Debounce_Debouncing(void)
{
  iBP1_DebounceCounter++;
  if ( iBP1_DebounceCounter == DEBOUNCE_TIME )
  {
    iBP1_EtatDebounce = ETAT_APPUYE;
    iBP1_DebounceCounter = 0;
  }
}
void BP1_Etat_Debounce_Appuye(void)
{
  iBp1 = digitalRead(BP1_PIN);
  if (iBp1 == LOW)
  {
    iBP1_EtatDebounce = ETAT_RELACHE;
  }    
}

bool BP1_BpEstIlAppuye(void)
{
  return (iBP1_EtatDebounce == ETAT_APPUYE);
}

void BP1_MAE_Setup(void)
{
    pinMode(BP1_PIN, INPUT);

    iBp1 = LOW;
    iBP1_DebounceCounter =0;
    iBP1_EtatDebounce = ETAT_RELACHE;
    
    
}

void BP1_MAE(void)
{
  if (iBP1_EtatDebounce == ETAT_RELACHE)
  {
    BP1_Etat_Debounce_Relache();
  }
  
  if (iBP1_EtatDebounce == ETAT_DEBOUNCING)
  {
    BP1_Etat_Debounce_Debouncing();
  }
  
  if (iBP1_EtatDebounce == ETAT_APPUYE)
  {
    BP1_Etat_Debounce_Appuye();
  }
  
}

