/*
    Created by Otobong James
    200317365
    This code uses a pir sensor on pin 10 and two leds on pin 9. it senses motion and activates a pulsing pattern in the leds

*/

int led = 9;
int pir = 10;
int pirState = LOW;
int value = 0;
int brightness = 0;
int fadeAmount = 5;

void fadein () { // this function controlls the fade in of the leds

  for (int fadeAmount = 0 ; fadeAmount <= 255; fadeAmount += 5) {
    analogWrite(led, fadeAmount);
    delay(5);
  }

}
void fadeout() { // this function controlls the fade in of the leds

  for (int fadeAmount = 255 ; fadeAmount >= 0; fadeAmount -= 5) {
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

  value = digitalRead(pir);


  if (value == HIGH) { // read if motion is detected
    pulsingEyes(); // if it is then use pulsingEye function
    delay (1000);

    if (pirState == LOW) {
      Serial.println("Motion Detected!"); // print out on serial monitor if motion is detected
      pirState = HIGH;
      delay(500);
    }

  } else {
    analogWrite(led, LOW); // if not motion, turn led off

    if (pirState == HIGH) {
      Serial.println("Motion Ended!"); // print out on serial monitor if motion has stopped
      pirState = LOW;
    }

  }


  delay(500);

}
