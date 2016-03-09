  
#include <math.h>

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
float x=4.7125;
float y;

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
          }else if(efect=="strobo"){
            strobo();
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
    
    y = (sin(x)+1)*(255/4);
    x+=.03;
    if(y<=0.09){
      Serial.println("***********************************************************");
      Serial.println(y);
      }
    
    if(red==0){
      copyRed=red;
    }else{
      if(red<y){
        copyRed=red;
      }else{
        copyRed = y;        
      }
      
    }
    if(green==0){
      copyGreen=green;
    }else{
      if(green<y){        
        copyGreen = green;
      }else{
        copyGreen = y;  
      }
    }
    if(blue==0){
      copyBlue=blue;
    }else{
      if(blue<=y){
         copyBlue = blue;
      }else{
        copyBlue = y; 
        
      }
    }
    
    analogWrite(RedPin, copyRed);
    analogWrite(GreenPin, copyGreen);
    analogWrite(BluePin, copyBlue);

}

void strobo(){
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
    
    y = (sin(x)+1)*(255/4);
    x+=1.5;
    
    if(y<=0.09){
      Serial.println("***********************************************************");
      Serial.println(y);
      }
    
    if(red==0){
      copyRed=red;
    }else{
      if(red<y){
        copyRed=red;
      }else{
        copyRed = y;        
      }
      
    }
    if(green==0){
      copyGreen=green;
    }else{
      if(green<y){        
        copyGreen = green;
      }else{
        copyGreen = y;  
      }
    }
    if(blue==0){
      copyBlue=blue;
    }else{
      if(blue<=y){
         copyBlue = blue;
      }else{
        copyBlue = y; 
        
      }
    }
    
    analogWrite(RedPin, copyRed);
    analogWrite(GreenPin, copyGreen);
    analogWrite(BluePin, copyBlue);

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
