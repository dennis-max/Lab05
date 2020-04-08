#include<Keypad.h>
#include"SevSeg.h"
const byte ROWS = 4; 
const byte COLS = 4;
int seg7[]={12,13,14,15,16,17,2};
char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67};
int i,j,c;
byte n=0;
char ch;

char keys[ROWS][COLS]={
  {'F','B','A','0'},{'E','3','2','1'},
  {'D','6','5','4'},{'C','9','8','7'}
};

byte rowPins[ROWS]={5,4,3,10};
byte colPins[COLS]={9,8,7,11};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup(){
  for(i=0;i<7;i++){
    pinMode(seg7[i],OUTPUT);
  }
  Serial.begin(9600);
}
void loop(){

  char key = keypad.getKey();

  if(key!=NO_KEY){
    Serial.println(key);
    if(key>='0' && key<='9')
    {
    n=key-'0';
  
    OutPort(TAB[n]);

  }
}
}
void OutPort(byte dat){
  for(j=0;j<7;j++){
    if(dat%2==1)
     digitalWrite(seg7[j],HIGH);
    else
     digitalWrite(seg7[j],LOW);
     dat=dat/2;
  }
}
