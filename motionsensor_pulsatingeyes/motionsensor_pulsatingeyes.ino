int led = 9;
int pir = 10;
int pirState = LOW;
int value = 0;
int brightness = 0;
int fadeAmount = 5;

void fadein (){ // this function controlls the fade in of the leds
  
  for(int fadeAmount = 0 ; fadeAmount <= 255; fadeAmount +=5) { 
    analogWrite(led, fadeAmount);         
    delay(5);
  }
  
  }
  void fadeout() { // this function controlls the fade in of the leds
    
  for(int fadeAmount = 255 ; fadeAmount >= 0; fadeAmount -=5) { 
      analogWrite(led, fadeAmount);         
    delay(2);                            
  }  
}
void pulse() { // this function combines the fade in and fade out functions to create a pulsing effect
  fadein();
  fadeout();
}

void pulsingEyes() { // this function calls the pulse effect
  pulse();
  pulse();
  pulse();
  pulse();
  fadein();
  analogWrite(led, 255);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
   pinMode(pir, INPUT);
   Serial.begin (9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  pulsingEyes(); // function call


  delay(500);      

}







  
  
  
