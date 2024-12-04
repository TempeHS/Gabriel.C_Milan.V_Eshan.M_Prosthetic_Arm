#include <Servo.h>

const int ultrasonicPin = 7;
const int speakerPin = 6;
const int servoPin = 4; // Servo pin

long duration;
int distance;

Servo myServo; // Create a Servo object

void setup() {
  Serial.begin(9600);
  pinMode(ultrasonicPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
 
  myServo.attach(servoPin); // Attach the servo to the pin
  myServo.write(0);         // Initial position at 0°
}

void loop() {
 
  // Ultrasonic sensor operation
  pinMode(ultrasonicPin, OUTPUT);
  digitalWrite(ultrasonicPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicPin, LOW);

  pinMode(ultrasonicPin, INPUT);
  duration = pulseIn(ultrasonicPin, HIGH);

  // Calculate distance
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  // If the distance is between 5 and 100 cm
  if (distance > 5 && distance < 100) {
    int beepDelay = map(distance, 5, 25, 50, 100);

    tone(speakerPin, 1000, 100); // Activate buzzer
    myServo.write(90);           // Rotate servo to 90°
    delay(beepDelay);            // Wait for the beep delay
  } else {
    noTone(speakerPin);          // Turn off the buzzer
    myServo.write(0);            // Reset servo to 0°
  }
}
      