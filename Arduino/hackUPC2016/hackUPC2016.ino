#include <Servo.h>
#include <LiquidCrystal.h>

Servo aziservo;
Servo altiservo;
const int AZI_SERVO_PIN = 9;
const int ALTI_SERVO_PIN = 10;
const int LAZOR_PIN = 13;
const int BUZZER_PIN = 6;
const int IMPERIALMARCH_PIN = 7;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  Serial.begin(9600); // set the baud rate
  Serial.println("Ready"); // print "Ready" once
  aziservo.attach(AZI_SERVO_PIN);
  altiservo.attach(ALTI_SERVO_PIN);
  aziservo.write(0);
  altiservo.write(0);
  pinMode(LAZOR_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(IMPERIALMARCH_PIN, INPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello universe!");
  lcd.setCursor(1, 1);
  lcd.print("Select a star");
  
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  if (Serial.available()) // only send data back if data has been sent
  {
    digitalWrite(LAZOR_PIN, LOW);

    String inStr = Serial.readString(); // read the incoming azimuth
    //Serial.print(inStr);
    int separationIndex = inStr.indexOf(' ');
    String aziString = inStr.substring(0, separationIndex);
    inStr = inStr.substring(separationIndex+1);
    separationIndex = inStr.indexOf(' ');
    String altiString = inStr.substring(0, separationIndex);
    String starName = inStr.substring(separationIndex+1, inStr.length()-1);
    Serial.print(inStr+" "+starName);

    lcd.clear();
    lcd.print(starName);

    int azimuth = aziString.toInt();
    int altitude = altiString.toInt();

    aziservo.write(0);
    altiservo.write(0);


    azimuth = map(azimuth, 0, 360, 360, 0);


    // If azimuth is over 180 degrees, let's fix this (servomotors rotate to a max of 180 degrees)
    if (azimuth > 180)
    {
      azimuth = azimuth - 180;
      altitude = 180 - altitude;
    }

    aziservo.write(azimuth);
    altiservo.write(altitude);

    //send the data back in a new line so that it is not all one long line
    Serial.print(azimuth);
    Serial.print(" ");
    Serial.println(altitude);
    playTone(1000, 200);
  }

  if (digitalRead(IMPERIALMARCH_PIN) == HIGH){
    Serial.print("bu");
    imperialMarch();
  }

  delay(100); // delay for 1/10 of a second
  digitalWrite(LAZOR_PIN, HIGH);
}
