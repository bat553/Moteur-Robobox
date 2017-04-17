/***********************/
/* MAIN */
/***********************/
/* Swano Lab - 2017 */
/***********************/

#include "moteurs.h"
#include "boutons.h"
#include "leds.h"

void setup() {
  BP1_MAE_Setup();
  BP2_MAE_Setup();
  MOTOR1_MAE_SETUP();
  MOTOR2_MAE_SETUP();
  LED1_Setup();
  LED2_Setup();


}

void loop()
{
  delay(1);
  BP1_MAE();
  BP2_MAE();
  LED1_MAE();
  LED2_MAE();
  MOTOR1_MAE();
  MOTOR2_MAE();

  if ( BP1_PRESSED__BP2_RELEASED() && (MOTOR1_IsMotorAt90() == false))
  {
    MOTOR1_GoTo_Sens1();
    LED1_SetLed_BLINK(500);
  }
  else
  {

    if ( BP1_PRESSED__BP2_RELEASED() && (MOTOR1_IsMotorAt90() == true) )
    {
      MOTOR2_GoTo_Sens1();
      LED1_SetLed_BLINK(500);
    }
    else
    {
      if ( ALL_BP_RELEASED() )
      {
        MOTOR1_STOP();
        MOTOR2_STOP();
        LED1_SetLed_OFF();
      }
    }
  }
  if ( BP2_PRESSED__BP1_RELEASED() && (MOTOR2_IsMotorAt0() == false))
  {
    MOTOR2_GoTo_Sens2();
    LED2_SetLed_BLINK(500);
  }
  else
  {
    if ( BP2_PRESSED__BP1_RELEASED() && (MOTOR2_IsMotorAt0() == true) )
    {

      MOTOR1_GoTo_Sens2();
      LED2_SetLed_BLINK(500);
    }
    else
    {
      if (ALL_BP_RELEASED() )
      {
        MOTOR1_STOP();
        MOTOR2_STOP();
        LED2_SetLed_OFF();
      }
    }

  }

}


