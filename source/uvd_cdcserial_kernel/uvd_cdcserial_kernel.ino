#include <DigiCDC.h>
int analogValue = 0;

void get_input() {
  
  if (SerialUSB.available()) {
    char input = SerialUSB.read();
    if (input == 'g'){
      SerialUSB.print("{\"exposure_level\":\""); 
        if(analogValue < 83){
           SerialUSB.print("low"); 
        }
        else if((analogValue < 142)&&(analogValue >= 83)){
           SerialUSB.print("moderate");    
        }
        else if((analogValue < 180)&&(analogValue >= 142)){
           SerialUSB.print("high"); 
        } 
        else if((analogValue < 240)&&(analogValue >= 180)){    
           SerialUSB.print("veryhigh"); 
        }
        else if(analogValue > 240){     
           SerialUSB.print("moderate"); 
        }    
        SerialUSB.print("\" ,\"real_data\":");
        SerialUSB.print(analogValue,DEC);
        SerialUSB.println("}");  
    }  
  }
  SerialUSB.delay(100);   
    
}

void get_uv()
{
  analogValue = analogRead(1);
  analogValue = (0.7 * analogValue + 0.3 * analogRead(1)) * 0.23;

  if(analogValue < 83){
    digitalWrite(0, LOW);   
    digitalWrite(1, LOW); 
  }
  else if((analogValue < 142)&&(analogValue >= 83)){
    digitalWrite(0, HIGH);   
    digitalWrite(1, LOW);
  }
  else if((analogValue < 180)&&(analogValue >= 142)){
    digitalWrite(0, LOW);    
    digitalWrite(1, HIGH); 
  } 
  else if((analogValue < 240)&&(analogValue >= 180)){    
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);
  }
  else if(analogValue > 240){     
    digitalWrite(0, HIGH);   
    digitalWrite(1, HIGH);
  } 

}

void setup() {

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  SerialUSB.begin();
  for (int i = 0; i < 4; i++)
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
    digitalWrite(1, HIGH);
    delay(200);
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    delay(200);
  }

}

void loop() {
  
  get_uv();
  get_input();
           
}
