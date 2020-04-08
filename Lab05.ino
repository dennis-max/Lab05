#include<Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4;

char keys[ROWS][COLS]={
  {'F','B','A','0'},{'E','3','2','1'},
  {'D','6','5','4'},{'C','9','8','7'}
};

byte rowPins[ROWS]={5,4,3,10};
byte colPins[COLS]={9,8,7,11};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup(){
  Serial.begin(9600);
}
void loop(){

  char key = keypad.getKey();

  if(key!=NO_KEY){
    Serial.println(key);
  }
}
