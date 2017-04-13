#include "DigiKeyboard.h"
void setup() {                

  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
  DigiKeyboard.sendKeyStroke(0);    
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(0, LOW);   
    digitalWrite(1, LOW); 
    delay(200);           
    digitalWrite(0, HIGH);   
    digitalWrite(1, LOW);
    delay(200);        
    digitalWrite(0, LOW);    
    digitalWrite(1, HIGH);
    delay(200);      
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);
    delay(200); 
    digitalWrite(0, LOW);   
    digitalWrite(1, LOW); 
    delay(200);           
    digitalWrite(0, HIGH);   
    digitalWrite(1, LOW);
    delay(200);        
    digitalWrite(0, LOW);    
    digitalWrite(1, HIGH);
    delay(200);      
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);   
  }

}

void loop() {       

  int analogValue = analogRead(1);
  analogValue = (0.7 * analogValue + 0.3 * analogRead(1)) * 0.23;
  
  char string[4];
  itoa(analogValue, string, 10);
  DigiKeyboard.print("----Welcome use GeekToy----\n");
  DigiKeyboard.delay(60);    
  DigiKeyboard.sendKeyStroke(0);    
  
  if(analogValue < 83){
    digitalWrite(0, LOW);   
    digitalWrite(1, LOW); 
    
    DigiKeyboard.print("UV index   0-2\nExposurelevel   low\nRealTime Data   ");
    DigiKeyboard.delay(60);
    DigiKeyboard.sendKeyStroke(0);  
    DigiKeyboard.println(string); 
  }
  else if((analogValue < 142)&&(analogValue >= 83)){
    digitalWrite(0, HIGH);   
    digitalWrite(1, LOW);
 
    DigiKeyboard.print("UV index   3-5\nExposurelevel   moderate\nRealTimeData   ");
    DigiKeyboard.delay(60);
    DigiKeyboard.sendKeyStroke(0);  
    DigiKeyboard.println(string); 

  }
  else if((analogValue < 180)&&(analogValue >= 142)){
    digitalWrite(0, LOW);    
    digitalWrite(1, HIGH);
    
    DigiKeyboard.print("UV index   6-7\nExposurelevel   high\nRealTimeData   ");
    DigiKeyboard.delay(60);
    DigiKeyboard.sendKeyStroke(0);  
    DigiKeyboard.println(string); 
  } 
  else if((analogValue < 240)&&(analogValue >= 180)){    
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);
    
    DigiKeyboard.print("UV index   8-10\nExposurelevel   very-high\nRealTimeData   ");
    DigiKeyboard.delay(60);
    DigiKeyboard.sendKeyStroke(0);  
    DigiKeyboard.println(string); 

  }
  else if(analogValue > 240){     
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);
   
    DigiKeyboard.print("UV index   11\nExposurelevel   extreme\nRealTimeData   ");
    DigiKeyboard.delay(60);
    DigiKeyboard.sendKeyStroke(0);  
    DigiKeyboard.println(string); 
  }
  while(true){}

}
