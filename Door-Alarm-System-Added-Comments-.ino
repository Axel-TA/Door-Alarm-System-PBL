// Door Alarm System
// Introduction to IoT - PBL
// Authors: Axel Tille-Ascencio, Corrado Palermo
// Date: May 6, 2025


#include <NewPing.h> // External library for ultrasonic sensor

//Names and set values for parts of the circuit
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
#define BUZZER_PIN 7
#define BUTTON_PIN 2

// Time (in milliseconds) the door must be open before buzzer sounds
#define DOOR_OPEN_DELAY 10000 // 10 seconds

//Creates a sonar object using the NewPing library
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 


// Functions to track door state and timing
bool buzzerSilenced = false; //Goes true if button is pressed to silence buzzer
long doorOpenTime = 0; //big number type used to measure time in milliseconds
bool doorWasOpen = false;

// Function 1: Check if the door is open
bool isDoorOpen(int distance) {     //This function takes a number and returns true if > 2
  return (distance > 2);           // If distance is greater than 2cm, assume door is open
}

// Function 2: Control the buzzer
void buzzcause(bool shouldBuzz) {
  if (shouldBuzz) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn buzzer on
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn buzzer off
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  delay(200); // Slows down how often system checks the door

  int distance = sonar.ping_cm(); // Get distance from sensor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  bool doorOpen = isDoorOpen(distance); // Calls said function with the distance that was measured

  // Check if button is pressed (LOW means pressed)
  if (digitalRead(BUTTON_PIN) == LOW) {
    buzzerSilenced = true;
    buzzcause(false); // Turn off buzzer
    Serial.println("Buzzer silenced by button.");
  }

  // If door is closed, reset everything
  if (!doorOpen) {
    doorOpenTime = 0;
    buzzerSilenced = false;
    buzzcause(false); // Turn off buzzer, resets timer
  }
  // If door just opened, start timing
  else if (doorOpen && !doorWasOpen) { 
    doorOpenTime = millis(); // Record the time when door opened
  }
  // If door has been open, check if delay has passed and buzzer is not silenced
  else if (doorOpen && !buzzerSilenced) {
    if (millis() - doorOpenTime >= DOOR_OPEN_DELAY) {
      buzzcause(true); // Sound the buzzer
      Serial.println("Door open too long! Buzzer ON.");
    } else {
      buzzcause(false); // Wait until delay passes
    }
  }

  // Remembers the last door state. So program detects door just opened. 
  doorWasOpen = doorOpen;
}