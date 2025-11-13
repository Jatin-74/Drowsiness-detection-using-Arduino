/*
  Project Argus - Buzzer Alert Controller (for USB setup)

  Listens for 1-character commands from the PC (Python script)
  and triggers a buzzer on Pin 8.
*/

// Define our output pin
const int BUZZER_PIN = 8;

char last_command = '0'; // '0' means "All Clear"

void setup() {
  // Start serial communication (must match Python)
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Start with buzzer off
}

void loop() {
  // Check if data is available from the PC
  if (Serial.available() > 0) {

    char command = Serial.read();

    if (command != last_command) {
      if (command == '0') {
        digitalWrite(BUZZER_PIN, LOW); // Turn Buzzer OFF
      } else {
        // Any other command ('E', 'Y', 'T', etc.) turns the buzzer ON
        digitalWrite(BUZZER_PIN, HIGH);
      }
      last_command = command; // Save the new state
    }
  }
}

