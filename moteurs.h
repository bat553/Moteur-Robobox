/***********************/
/* MAE MOTEUR */
/***********************/
/* Swano Lab - 2017 */
/***********************/
#ifndef _MOTOR_H_ 
#define _MOTOR_H_ 
#include <Servo.h>

void MOTOR1_MAE_SETUP(void);
void MOTOR1_MAE(void);
void MOTOR1_GoTo_Sens1(void);
void MOTOR1_GoTo_Sens2(void);
void MOTOR1_STOP(void);
bool MOTOR1_IsMotorAt0(void);
bool MOTOR1_IsMotorAt90(void);

void MOTOR2_MAE_SETUP(void);
void MOTOR2_MAE(void);
void MOTOR2_GoTo_Sens1(void);
void MOTOR2_GoTo_Sens2(void);
void MOTOR2_STOP(void);
bool MOTOR2_IsMotorAt0(void);
bool MOTOR2_IsMotorAt90(void);

enum
{
  ETAT_ARRETE,
  ETAT_SENS_1,
  ETAT_SENS_2
};

#define MOTOR_DELAY 10



#endif
