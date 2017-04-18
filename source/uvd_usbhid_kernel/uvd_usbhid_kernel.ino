#include <DigiUSB.h>
int analogValue = 0; 

void get_input() {
  while (true) { 
    if (DigiUSB.available()) {
      int usb_read = DigiUSB.read();
      if (usb_read == 'g') {
        DigiUSB.print("{ \"exposure_level\":\""); 
        if(analogValue < 83){
           DigiUSB.print("low"); 
        }
        else if((analogValue < 142)&&(analogValue >= 83)){
           DigiUSB.print("moderate");    
        }
        else if((analogValue < 180)&&(analogValue >= 142)){
           DigiUSB.print("high"); 
        } 
        else if((analogValue < 240)&&(analogValue >= 180)){    
           DigiUSB.print("veryhigh"); 
        }
        else if(analogValue > 240){     
           DigiUSB.print("extreme"); 
        }         
        DigiUSB.print("\" , \"real_data\":\"");
        DigiUSB.print(analogValue,DEC);
        DigiUSB.println("\" }");        
        break;  
      }
      else{ 
      }
    }
    DigiUSB.delay(10);
  }
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
  DigiUSB.begin();

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
