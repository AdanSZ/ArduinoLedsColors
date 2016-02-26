  
#define RedPin 5
#define GreenPin 3
#define BluePin 6
int i=0;
int red;
int blue;
int green;
int copyRed;
int copyBlue;
int copyGreen;
String efect;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;
int bandera_ef = 0;
void setup() // Se ejecuta cada vez que el Arduino se inicia
{ 
  Serial.begin(9600);
  pinMode(RedPin,OUTPUT);  //El LED Rojo como una salida
  pinMode(GreenPin,OUTPUT); //El LED Verde como una salida
  pinMode(BluePin,OUTPUT);  //El LED Azul como una salida
}

void loop()
{                             
        read();
        
        if(efect == "fade"){
              Serial.println("en el if");              
              fade();
        }else if(efect == "solid"){
              solid();
          }       
}
void cambio_efect(){
        analogWrite(RedPin, 10);
        analogWrite(GreenPin, 0);
        analogWrite(BluePin, 10);  
  }
void fade(){
    Serial.println(bandera_ef);
    Serial.println(efect);
    read();
    if(bandera_ef!=1){
      Serial.println("En el copy");
      copyRed = red;
      copyBlue = blue;
      copyGreen = green;

          Serial.println(copyRed);   
          Serial.println(copyGreen);   
          Serial.println(copyBlue); 
    }
    
    bandera_ef=1;
    
     for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255): 
          if(red!=0) copyRed=fadeValue;
          if(green!=0) copyGreen=fadeValue;
          if(blue!=0) copyBlue=fadeValue;                
          analogWrite(RedPin, copyRed);
          analogWrite(GreenPin, copyGreen);
          analogWrite(BluePin, copyBlue); 
          
      // wait for 30 milliseconds to see the dimming effect
      delay(30);
    }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
          if(red!=0) copyRed=fadeValue;
          if(green!=0) copyGreen=fadeValue;
          if(blue!=0) copyBlue=fadeValue;          
          analogWrite(RedPin, copyRed);
          analogWrite(GreenPin, copyGreen);
          analogWrite(BluePin, copyBlue);
          
      delay(30);
    }
    
}

 void solid(){
   analogWrite(RedPin, red);
   analogWrite(GreenPin, green);
   analogWrite(BluePin, blue); 
  }

 void read(){
  if (Serial.available() > 0) {
                cambio_efect();         
                bandera_ef=0;                                         
                  efect = Serial.readStringUntil(',');
                  Serial.read();
                  String R  = Serial.readStringUntil(',');
                  Serial.read();
                  String G = Serial.readStringUntil(',');
                  Serial.read();
                  //String B  = Serial.readStringUntil('\0');
                  String B  = Serial.readString();                          
                    red = R.toInt();
                    blue = B.toInt();
                    green = G.toInt();
              Serial.println(efect);
//              cambio_efect();
              delay(30);            
             }  

  }
