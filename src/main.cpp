/*
 * project based on www.theorycircuit.com
 * code by Crenn from http://thebestcasescenario.com thank you!
 */

#include <Arduino.h>

//Varibles used for calculations
int NbTopsFan, Calc;

//The pin location of the sensor
int hallsensor = 2;
typedef struct {
  //Defines the structure for multiple fans and
  //their dividers
  char fantype;
  unsigned int fandiv;
} fanspec;

//Definitions of the fans
//This is the varible used to select the fan and it's divider,
//set 1 for unipole hall effect sensor
//and 2 for bipole hall effect sensor
fanspec fanspace[3]={{0,1},{1,2},{2,8}};
uint8_t fan = 1;

//This is the function that the interupt calls
void rpm() {
  NbTopsFan++;
}

void setup() {
  pinMode(hallsensor, INPUT);
  Serial.begin(9600);
  attachInterrupt(0, rpm, RISING);
}

void loop () {
  NbTopsFan = 0;  //Set NbTops to 0 ready for calculations
  sei();  //Enables interrupts
  delay(1000);
  cli();  //Disable interrupts

  //Times NbTopsFan (which is apprioxiamately the fequency the fan
  //is spinning at) by 60 seconds before dividing by the fan's divider
  Calc = ((NbTopsFan * 60)/fanspace[fan].fandiv);

  Serial.print(Calc, DEC);
  Serial.print(" rpm\r\n");
}
