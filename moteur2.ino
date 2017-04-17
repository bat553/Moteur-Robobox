/***********************/
/* MAE MOTEUR */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#include "moteurs.h"
#include <Servo.h>

int MOTOR2_iEtatEnCours;
int MOTOR2_posiMotor;

Servo MOTOR2_monServo;


void MOTOR2_MAE_SETUP(void)
{

  MOTOR2_monServo.attach(4);
  MOTOR2_posiMotor = 0;

}

void MOTOR2_Etat_Arrete(void)
{

}


void MOTOR2_Etat_Sens1(void)
{

  if ( MOTOR2_posiMotor < 90)
  {
    MOTOR2_posiMotor ++;
  }
  else
  {
    MOTOR2_iEtatEnCours = ETAT_ARRETE;
  }
}


void MOTOR2_Etat_Sens2(void)
{
  if ( MOTOR2_posiMotor > 0)
  {
    MOTOR2_posiMotor --;
  }
  else
  {
    MOTOR2_iEtatEnCours = ETAT_ARRETE;
  }
}

void MOTOR2_GoTo_Sens1(void)
{
  MOTOR2_iEtatEnCours = ETAT_SENS_1;
}


void MOTOR2_GoTo_Sens2(void)
{
  MOTOR2_iEtatEnCours = ETAT_SENS_2;
}

void MOTOR2_STOP(void)
{
  MOTOR2_iEtatEnCours = ETAT_ARRETE;
}

bool MOTOR2_IsMotorAt0(void)
{
  return (MOTOR2_posiMotor == 0);
}

bool MOTOR2_IsMotorAt90(void)
{
  return (MOTOR2_posiMotor == 90);
}


void MOTOR2_MAE(void)
{
  if (MOTOR2_iEtatEnCours == ETAT_ARRETE)
  {
    MOTOR2_Etat_Arrete();
  }
  if (MOTOR2_iEtatEnCours == ETAT_SENS_1)
  {
    MOTOR2_Etat_Sens1();
  }
  if (MOTOR2_iEtatEnCours == ETAT_SENS_2)
  {
    MOTOR2_Etat_Sens2();
  }

  MOTOR2_monServo.write(MOTOR2_posiMotor);


}

