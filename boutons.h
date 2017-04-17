/***********************/
/* MAE DEBOUNCE */
/***********************/
/* Swano Lab - 2017 */
/***********************/

#ifndef _BOUTON_H_ 
#define _BOUTON_H_ 

void BP1_Etat_Debounce_Relache(void);
void BP1_Etat_Debounce_Debouncing(void);
void BP1_Etat_Debounce_Appuye(void);
bool BP1_BpEstIlAppuye(void);
void BP1_MAE_Setup(void);
void BP1_MAE(void);


void BP2_Etat_Debounce_Relache(void);
void BP2_Etat_Debounce_Debouncing(void);
void BP2_Etat_Debounce_Appuye(void);
bool BP2_BpEstIlAppuye(void);
void BP2_MAE_Setup(void);
void BP2_MAE(void);

enum
{
  ETAT_RELACHE,
  ETAT_DEBOUNCING,
  ETAT_APPUYE
};

#define BP1_PIN 7
#define BP2_PIN 8
#define DEBOUNCE_TIME 10

#define ALL_BP_RELEASED() (BP1_BpEstIlAppuye() == false) && (BP2_BpEstIlAppuye() == false)
#define BP1_PRESSED__BP2_RELEASED()  (BP1_BpEstIlAppuye() == true) && (BP2_BpEstIlAppuye() == false)
#define BP2_PRESSED__BP1_RELEASED()  (BP1_BpEstIlAppuye() == false) && (BP2_BpEstIlAppuye() == true)
#define ALL_BP_PRESSED() (BP1_BpEstIlAppuye() == true) && (BP2_BpEstIlAppuye() == true)


#endif
