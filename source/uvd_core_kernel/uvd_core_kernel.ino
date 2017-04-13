void setup() {                

  pinMode(0, OUTPUT);  
  pinMode(1, OUTPUT);  
    
  for(int i = 0; i < 4; i++)
  {   
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

  int analogValue = analogRead(1);
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
  
  delay(200);

}




 
