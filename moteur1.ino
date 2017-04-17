/***********************/
/* MAE MOTEUR */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#include "moteurs.h"
#include <Servo.h>

int MOTOR1_iEtatEnCours;
int MOTOR1_posiMotor;
int MOTOR1_LowSpeedCounter;
Servo MOTOR1_monServo;


void MOTOR1_MAE_SETUP(void)
{

  MOTOR1_monServo.attach(2);
  MOTOR1_posiMotor = 0;
  MOTOR1_LowSpeedCounter = 0;

}

void MOTOR1_Etat_Arrete(void)
{
  MOTOR1_LowSpeedCounter = 0;
}


void MOTOR1_Etat_Sens1(void)
{

  MOTOR1_LowSpeedCounter ++;
  if ( MOTOR1_LowSpeedCounter == MOTOR_DELAY)
  {
    MOTOR1_LowSpeedCounter = 0;
    if ( MOTOR1_posiMotor < 90)
    {
      MOTOR1_posiMotor ++;
    }
    else
    {
      MOTOR1_iEtatEnCours = ETAT_ARRETE;
    }
  }
}


void MOTOR1_Etat_Sens2(void)
{
  MOTOR1_LowSpeedCounter ++;
  if ( MOTOR1_LowSpeedCounter ==  MOTOR_DELAY)
  {
    MOTOR1_LowSpeedCounter = 0;
    if ( MOTOR1_posiMotor > 0)
    {
      MOTOR1_posiMotor --;
    }
    else
    {
      MOTOR1_iEtatEnCours = ETAT_ARRETE;
    }
  }
}

void MOTOR1_GoTo_Sens1(void)
{
  MOTOR1_iEtatEnCours = ETAT_SENS_1;
}


void MOTOR1_GoTo_Sens2(void)
{
  MOTOR1_iEtatEnCours = ETAT_SENS_2;
}

void MOTOR1_STOP(void)
{
  MOTOR1_iEtatEnCours = ETAT_ARRETE;
}

bool MOTOR1_IsMotorAt0(void)
{
  return (MOTOR1_posiMotor == 0);
}

bool MOTOR1_IsMotorAt90(void)
{
  return (MOTOR1_posiMotor == 90);
}

void MOTOR1_MAE(void)
{
  if (MOTOR1_iEtatEnCours == ETAT_ARRETE)
  {
    MOTOR1_Etat_Arrete();
  }
  if (MOTOR1_iEtatEnCours == ETAT_SENS_1)
  {
    MOTOR1_Etat_Sens1();
  }
  if (MOTOR1_iEtatEnCours == ETAT_SENS_2)
  {
    MOTOR1_Etat_Sens2();
  }

  MOTOR1_monServo.write(MOTOR1_posiMotor);

}

