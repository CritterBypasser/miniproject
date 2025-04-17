#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 10  // Change this to your SD module's CS pin
#define BUTTON_PIN 2         // Button to toggle play/pause
 
TMRpcm audio;
bool isPlaying = false; // Track play/pause state

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Internal pull-up resistor enabled
  SD.begin(SD_ChipSelectPin);
  audio.speakerPin = 9; // Speaker connected to pin 9
  audio.volume(3);
  audio.play("1.wav"); // Start playing
  isPlaying = true;
}

void loop() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect button press (falling edge)
  if (lastButtonState == HIGH && buttonState == LOW) {
    delay(50); // Debounce delay
    if (isPlaying) {
      audio.pause(); // Pause music
      isPlaying = false;
    } else {
      audio.play("2.wav"); // Resume music
      isPlaying = true;
    }
  }
if (!audio.isPlaying()) {
  digitalWrite(9, LOW);  // Stop PWM output to speaker
}

  lastButtonState = buttonState;
}
