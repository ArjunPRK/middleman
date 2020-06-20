
#include <Servo.h>
#define slider 2
#define pot A0
#define motor 4
Servo myservo; 
Servo myservo1;
int oldstate=0;
int slidestate = 0; 
int potread=0; 
int val=0;
void setup()
{
  Serial.begin(9600);
  pinMode(slider, INPUT);
  pinMode(pot, INPUT);
  pinMode(motor, OUTPUT);
  myservo.attach(6);
  myservo1.attach(9);
}

void loop()
{
  slidestate=digitalRead(slider);
  potread=analogRead(pot);
  switch(slidestate)
  {
    case HIGH:
        if(slidestate!=oldstate)
        {
            myservo.write(0);
            delay(2000);
        }
    break;
    case LOW:
    	if(slidestate!=oldstate)
        {
            myservo.write(180);
            delay(2000);
        }
        val = analogRead(pot);            
        val = map(val, 0, 1023, 0, 180);   
        myservo1.write(val);                 
        delay(1); 
    break;
  }
  oldstate=slidestate;
}
