/*
 * 
Credits: 
1) Servo Code: https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
2) Ultrasonic Sensor: http://arduinobasics.blogspot.in/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 "This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012."
3) Param Agarwal - https://www.hackster.io/paramaggarwal/mapping-a-room-with-ultrasonic-distance-sensors-9725b7
4) https://github.com/paramaggarwal/pingray
*/
 
#include <Servo.h>
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 300; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

 
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
  
}
 
 
void loop()
{

  for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);   

          /* The following trigPin/echoPin cycle is used to determine the
       distance of the nearest object by bouncing soundwaves off of it. */ 
       digitalWrite(trigPin, LOW); 
       delayMicroseconds(2); 
      
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10); 
       
       digitalWrite(trigPin, LOW);
       duration = pulseIn(echoPin, HIGH);
       
       //Calculate the distance (in cm) based on the speed of sound.
       distance = duration/58.2;
       
       if (distance >= maximumRange || distance <= minimumRange){
       /* Send a negative number to computer and Turn LED ON 
       to indicate "out of range" */
       //Serial.println("-1");
       digitalWrite(LEDPin, HIGH); 
       }
       else {
       /* Send the distance to the computer using Serial protocol, and
       turn LED OFF to indicate successful reading. */
       Serial.print(distance);
       Serial.print(" ");
       Serial.println(servoAngle);
       digitalWrite(LEDPin, LOW); 
       }
       
       //Delay 50ms before next reading.
       delay(50);
      
                     
  }
 
  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    servo.write(servoAngle);          

              /* The following trigPin/echoPin cycle is used to determine the
       distance of the nearest object by bouncing soundwaves off of it. */ 
       digitalWrite(trigPin, LOW); 
       delayMicroseconds(2); 
      
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10); 
       
       digitalWrite(trigPin, LOW);
       duration = pulseIn(echoPin, HIGH);
       
       //Calculate the distance (in cm) based on the speed of sound.
       distance = duration/58.2;
       
       if (distance >= maximumRange || distance <= minimumRange){
       /* Send a negative number to computer and Turn LED ON 
       to indicate "out of range" */
       //Serial.println("-1");
       digitalWrite(LEDPin, HIGH); 
       }
       else {
       /* Send the distance to the computer using Serial protocol, and
       turn LED OFF to indicate successful reading. */
       Serial.print(distance);
       Serial.print(" ");
       Serial.println(servoAngle);
       digitalWrite(LEDPin, LOW); 
       }
       
       //Delay 50ms before next reading.
       delay(50);
      }
      
  }
  //end control the servo's speed  

