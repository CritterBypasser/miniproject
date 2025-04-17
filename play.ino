#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 10  // SD card module CS pin
#define BUTTON_PIN 2         // Button to toggle play/pause
#define SPEAKER_PIN 9        // Speaker pin

TMRpcm audio;
bool isPlaying = false;
unsigned long playStartTime = 0;  // Start time when playing
unsigned long pausedTime = 0;      // Track elapsed time before pause

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  SD.begin(SD_ChipSelectPin);
  audio.speakerPin = SPEAKER_PIN;

  Serial.begin(9600);
  Serial.println("Press button to start playback.");
}

void loop() {
  static bool lastButtonState = HIGH;
  bool buttonState = digitalRead(BUTTON_PIN);

  // Detect button press (falling edge)
  if (lastButtonState == HIGH && buttonState == LOW) {
    delay(50);  // Debounce

    if (isPlaying) {
      pausedTime += millis() - playStartTime;  // Save elapsed time
      Serial.print("Pausing at: ");
      Serial.println(pausedTime / 1000); // Convert to seconds
      audio.stopPlayback();  // Stop playback
      isPlaying = false;
    } else {
      Serial.print("Resuming from: ");
      Serial.println(pausedTime / 1000);
      audio.play("music.wav", pausedTime / 1000);  // Restart from estimated time
      playStartTime = millis();  // Reset play start time
      isPlaying = true;
    }
  }

  lastButtonState = buttonState;
}
