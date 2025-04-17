#include "SD.h"      // SD card library
#include "TMRpcm.h"  // Audio File Library
#include "SPI.h"     // SPI library for SD card

#define SD_ChipSelectPin 10

TMRpcm music;
int button1, button2;
int song_number = 1;
bool isPaused = false;
unsigned long songStartTime = 0;
unsigned long pausedTime = 0;

void setup()
{
    music.speakerPin = 9; // Audio output pin
    Serial.begin(9600);

    Serial.print("Initializing SD Card...");
    if (!SD.begin(SD_ChipSelectPin)) {
        Serial.println(" SD Initialization Failed!");
        while (1); // Stop execution if SD fails
    }
    Serial.println(" SD Card Initialized Successfully!");
    pinMode(2, INPUT_PULLUP); // Next track button
    pinMode(3, INPUT_PULLUP); // Play/pause button

    music.setVolume(3); // Volume level 0-7
    music.quality(1);   // Set 1 for 2x oversampling, 0 for normal
}

void loop()
{
    button1 = digitalRead(2);
    button2 = digitalRead(3);
    delay(50);  // Button debounce

    if (button2 == LOW) // Play/Pause
    {
        if (music.isPlaying()) {
            Serial.println("Pausing...");
            pausedTime = millis() - songStartTime; // Save elapsed time
            music.disable(); // Stop playback
            isPaused = true;
        } else {
            Serial.println("Resuming...");
            playSong(song_number, pausedTime / 1000); // Resume from last position
            isPaused = false;
        }
        delay(300);
    }

    if (button1 == LOW) // Change Song
    {
        song_number++;
        if (song_number == 8) { song_number = 1; } // Loop through 7 songs
        playSong(song_number, 0);
        isPaused = false;
        delay(300);
    }
}

void playSong(int song_number, int startTime)
{
    songStartTime = millis(); // Reset timer
    pausedTime = 0; // Reset paused time

    switch (song_number) {
        case 1: music.play("1.wav", startTime+30); break;
        case 2: music.play("2.wav", startTime); break;
        case 3: music.play("3.wav", startTime); break;
        case 4: music.play("4.wav", startTime); break;
        case 5: music.play("5.wav", startTime); break;
        case 6: music.play("6.wav", startTime); break;
        case 7: music.play("7.wav", startTime); break;
    }
}
