#include <Servo.h>
Servo aziservo;
Servo altiservo;
const int AZI_SERVO_PIN = 9;
const int ALTI_SERVO_PIN = 10;

void setup() {
  
  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once
  aziservo.attach(AZI_SERVO_PIN);
  altiservo.attach(ALTI_SERVO_PIN);
  
}

void loop() {
  
  char inByte = ' ';
  if (Serial.available()) // only send data back if data has been sent
  {
    String inStr1 = Serial.readString(); // read the incoming azimuth
    String inStr2 = Serial.readString(); // read the incoming altitude
   
    char aziBuf[inStr1.length()+1];
    char altiBuf[inStr2.length()+1];

    inStr1.toCharArray(aziBuf, inStr1.length()+1);
    inStr2.toCharArray(altiBuf, inStr2.length()+1);
    
    int azimuth = atoi(aziBuf);
    int altitude = atoi(altiBuf);

    aziservo.write(0);
    altiservo.write(0);

    // If azimuth is over 180 degrees, let's fix this (servomotors rotate to a max of 180 degrees)
    if (azimuth > 180)
    {
      azimuth = azimuth - 180;
      altitude = altitude - 90;
    }

    aziservo.write(azimuth);
    altiservo.write(altitude);

    // send the data back in a new line so that it is not all one long line
    Serial.print(azimuth);
    Serial.print(" ");
    Serial.println(altitude);
  }
  
  delay(100); // delay for 1/10 of a second
  
}
