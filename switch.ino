//#include "SD.h"         // SD card library
//#include "TMRpcm.h"     // Audio File Library
//#include "SPI.h"        // SPI library for SD card
//
//#define SD_ChipSelectPin 10
//
//TMRpcm music;
//int song_number = 1;
//bool isPaused = false;
//
//const int button1 = 2;  // Next song
//const int button2 = 3;  // Pause/Resume Toggle
//
//// ** Function Prototype **
//void playSong(int song_number);
//
//void setup() {
//    music.speakerPin = 9;  // Audio output pin from Arduino
//    Serial.begin(9600);
//
//    if (!SD.begin(SD_ChipSelectPin)) {
//        Serial.println("SD Initialization Failed!");
//        while (1);  // Stop execution
//    }
//    Serial.println("SD Card Initialized");
//
//    music.setVolume(7);  // Volume level (0 to 7)
//    music.quality(1);    // Set 1 for 2x oversampling, Set 0 for normal
//
//    pinMode(button1, INPUT_PULLUP);
//    pinMode(button2, INPUT_PULLUP);
//
//    playSong(song_number);
//}
//
//void loop() {
//    if (digitalRead(button1) == LOW) {
//        changeSong();
//        delay(300);  // Debounce delay
//    }
//    if (digitalRead(button2) == LOW) {
//        togglePause();
//        delay(300);  // Debounce delay
//    }
//}
//
//void changeSong() {
//    song_number++;
//    if (song_number > 7) {
//        song_number = 1;
//    }
//    Serial.print("Playing Song: ");
//    Serial.println(song_number);
//    playSong(song_number);
//}
//
//void togglePause() {
//    if (music.isPlaying()) {
//        Serial.println("Paused");
//        music.pause();
//        isPaused = true;
//    } else {
//        Serial.println("Resumed");
//        playSong(song_number);  // Restart song
//        isPaused = false;
//    }
//}
//
//// ** Function Definition: playSong() **
//void playSong(int song_number) {
//    char filename[10];  // Buffer to hold filename (e.g., "1.wav\0")
//    sprintf(filename, "%d.wav", song_number);  // Convert to C-string
//    Serial.print("Playing: ");
//    Serial.println(filename);
//    music.play(filename);  // Play the audio file
//}

//#include "SD.h" //SD card library
//#include "TMRpcm.h" //Audio File Library
//#include "SPI.h" //SPI library for SD card
//#define SD_ChipSelectPin 10
//
//TMRpcm music;
//int button1, button2;
//
//int song_number=0;
//boolean play_pause;
//
//void setup()
//{
//music.speakerPin = 9; //Audio output pin from Arduino
//Serial.begin(9600);
//if (!SD.begin(10))
//{
//Serial.println("SD fail");
//return;
//}
//Serial.println("ok");
//pinMode(2, INPUT_PULLUP); //Pull up for change track switch
//pinMode(3, INPUT_PULLUP); //Pull up for play/pause switch
////pinMode(3, INPUT_PULLUP); //Pull up for fast forward
//music.setVolume(5); // 0 to 7. Set volume level
//music.quality(1); // Set 1 for 2x oversampling Set 0 for normal
//}
//
//void loop()
//{
//button1 = digitalRead(2);
//button2 = digitalRead(3);
//
//bool isPlaying = false;
//
//
//    if (digitalRead(buttonPin) == LOW) {
//        delay(200);  // Debounce delay
//
//        isPlaying = !isPlaying;
//        Serial.println(isPlaying ? "Play" : "Pause");
//
//        while (digitalRead(buttonPin) == LOW); // Wait for button release
//    }
//
////if (button1 == LOW) //Button 1 Pressed
//{
//song_number++;
//if (song_number==7)
//{song_number=1;}
//if (song_number ==1)
//{music.play("1.wav",25);} //Play song 1 from 10th second
//if (song_number ==2)
//{music.play("2.wav",20);} //Play song 2 from 33rd second
//if (song_number ==3)
//{music.play("3.wav",15);} //Play song 3 from start
//if (song_number ==4)
//{music.play("4.wav",71);} //Play song 4 from 25th second
//if (song_number ==5)
//{music.play("5.wav");} //Play song 5 from start
//if (song_number ==6)
//{music.play("6.wav",58);} //Play song 6 from start }
//}
//delay(200);
//} 
////
//
//#include "SD.h"         // SD card library
//#include "TMRpcm.h"     // Audio File Library
//#include "SPI.h"        // SPI library for SD card
//
//#define SD_ChipSelectPin 10
//
//TMRpcm music;
//int song_number = 1;
//bool isPaused = false;
//int lastSong = 1;
//
//const int button1 = 2;  // Next song
//const int button2 = 3;  // Pause
//const int button3 = 4;  // Resume
//
//void setup() {
//    music.speakerPin = 9;  // Audio output pin from Arduino
//    Serial.begin(9600);
//    
//    if (!SD.begin(SD_ChipSelectPin)) {
//        return;
//    }
//    Serial.println("SD Card OK");
//
//    music.setVolume(3);  // 0 to 7. Set volume level
//    music.quality(1);    // Set 1 for 2x oversampling, Set 0 for normal
//
//    pinMode(button1, INPUT_PULLUP);
//    pinMode(button2, INPUT_PULLUP);
//    pinMode(button3, INPUT_PULLUP);
//}
//
//void loop() {
//    if (digitalRead(button1) == LOW) {
//        changeSong();
//        delay(300);  // Debounce delay
//    }
//    if (digitalRead(button2) == LOW) {
//        pauseSong();
//        delay(300);
//    }
//    if (digitalRead(button3) == LOW) {
//        resumeSong();
//        delay(300);
//    }
//}
//
//void changeSong() {
//    song_number++;
//    if (song_number == 7) {
//        song_number = 1;
//    }
//    Serial.print("Playing Song: ");
//    playSong(song_number);
//}
//
//
//
//void pauseSong() {
//    if (music.isPlaying()) {
//        Serial.println("Paused");
//        music.pause();  // Stop playback
//        isPaused = true;
//        lastSong = song_number;
//    }
//}
//
//void resumeSong() {
//    if (isPaused) {
//        Serial.print("Resuming Song: ");
//        Serial.println(lastSong);
//        playSong(lastSong);
//        isPaused = false;
//    }
//}
//
//void playSong(int song_number) {
//    switch (song_number) {
//        case 1: music.play("1.wav", 25); break;
//        case 2: music.play("2.wav", 20); break;
//        case 3: music.play("3.wav", 15); break;
//        case 4: music.play("4.wav", 71); break;
//        case 5: music.play("5.wav", 60); break;
//        case 6: music.play("6.wav", 58); break;
//    }
//}

//
//#include "SD.h"         // SD card library
//#include "TMRpcm.h"     // Audio File Library
//#include "SPI.h"        // SPI library for SD card
//
//#define SD_ChipSelectPin 10
//
//TMRpcm music;
//int song_number = 1;
//bool isPaused = false;
//unsigned long startTime = 0;  // Store start time
//unsigned long pauseTime = 0;  // Store paused position
//
//const int button1 = 2;  // Next song
//const int button2 = 3;  // Pause
//const int button3 = 4;  // Resume
//
//// ** Function Prototypes (Important) **
//void playSong(int song_number, int startOffset = 0);
//
//void setup() {
//    music.speakerPin = 9;  // Audio output pin from Arduino
//    Serial.begin(9600);
//    
//    if (!SD.begin(SD_ChipSelectPin)) {
//        Serial.println("SD fail");
//        return;
//    }
//    Serial.println("SD Card OK");
//
//    music.setVolume(3);  // 0 to 7. Set volume level
//    music.quality(1);    // Set 1 for 2x oversampling, Set 0 for normal
//
//    pinMode(button1, INPUT_PULLUP);
//    pinMode(button2, INPUT_PULLUP);
//    pinMode(button3, INPUT_PULLUP);
//}
//
//void loop() {
//    if (digitalRead(button1) == LOW) {
//        changeSong();
//        delay(300);  // Debounce delay
//    }
//    if (digitalRead(button2) == LOW) {
//        pauseSong();
//        
//    }
//    if (digitalRead(button3) == LOW) {
//        resumeSong();
//        delay(300);
//    }
//}
//
//void changeSong() {
//    song_number++;
//    if (song_number > 6) {
//        song_number = 1;
//    }
//    Serial.print("Playing Song: ");
//    Serial.println(song_number);
//    playSong(song_number);
//}
//
//void pauseSong() {
//    if (music.isPlaying()) {
//        Serial.println("Paused");
//        music.pause();  // Stop playback
//        isPaused = true;
//        pauseTime = millis() - startTime; // Store elapsed time
//    }
//}
//
//void resumeSong() {
//    if (isPaused) {
//        Serial.print("Resuming from: ");
//        Serial.println(pauseTime / 1000);  // Convert ms to seconds
//        playSong(song_number, pauseTime / 1000);  // Resume from last position
//        isPaused = false;
//    }
//}
//
//// ** Function Definition: playSong() **
//void playSong(int song_number, int startOffset) {
//    startTime = millis();  // Reset start time
//    switch (song_number) {
//        case 1: music.play("1.wav", 25 + startOffset); break;
//        case 2: music.play("2.wav", 20 + startOffset); break;
//        case 3: music.play("3.wav", 15 + startOffset); break;
//        case 4: music.play("4.wav", 71 + startOffset); break;
//        case 5: music.play("5.wav", 60 + startOffset); break;
//        case 6: music.play("6.wav", 58 + startOffset); break;
//    }
//}
//
//#include "SD.h"         // SD card library
//#include "TMRpcm.h"     // Audio File Library
//#include "SPI.h"        // SPI library for SD card
//
//#define SD_ChipSelectPin 10
//
//TMRpcm music;
//int song_number = 1;
//bool isPaused = false;
//unsigned long startTime = 0;  // Store start time
//unsigned long pauseTime = 0;  // Store paused position
//
//const int button1 = 2;  // Next song
//const int button2 = 3;  // Pause
//const int button3 = 4;  // Resume
//
//// ** Function Prototypes (Important) **
//void playSong(int song_number, int startOffset = 0);
//
//void setup() {
//    music.speakerPin = 9;  // Audio output pin from Arduino
//    Serial.begin(9600);
//    SD.begin(10);
//    if (!SD.begin(SD_ChipSelectPin)) {
//        Serial.println("SD fail");
//        return;
//    }
//    Serial.println("SD Card OK");
//
//    music.setVolume(4);  // 0 to 7. Set volume level
//    music.quality(1);    // Set 1 for 2x oversampling, Set 0 for normal
//
//    pinMode(button1, INPUT_PULLUP);
//    pinMode(button2, INPUT_PULLUP);
//    pinMode(button3, INPUT_PULLUP);
//}
//
//void loop() {
//
//  if (!SD.begin(SD_ChipSelectPin)) {
//        Serial.println("SD fail");
//        return;
//    }
//    Serial.println("SD Card OK");
//
//    if (digitalRead(button1) == LOW) {
//        changeSong();
//        delay(300);  // Debounce delay
//    }
//    if (digitalRead(button2) == LOW) {
//        pauseSong();
//        
//    }
//    if (digitalRead(button3) == LOW) {
//        resumeSong();
//        delay(300);
//    }
//}
//
//void changeSong() {
//    song_number++;
//    if (song_number > 7) {
//        song_number = 1;
//    }
//    Serial.print("Playing Song: ");
//    Serial.println(song_number);
//    playSong(song_number);
//}
//
//void pauseSong() {
//    if (music.isPlaying()) {
//        Serial.println("Paused");
//        music.pause();  // Stop playback
//        isPaused = true;
//        pauseTime = millis() - startTime; // Store elapsed time
//    }
//}
//
//void resumeSong() {
//    if (isPaused) {
//        Serial.print("Resuming from: ");
//        Serial.println(pauseTime / 1000);  // Convert ms to seconds
//        playSong(song_number, pauseTime / 1000);  // Resume from last position
//        isPaused = false;
//    }
//}
//
//// ** Function Definition: playSong() **
//void playSong(int song_number, int startOffset) {
//    startTime = millis();  // Reset start time
//    switch (song_number) {
//        case 1: music.play("1.wav", 30 + startOffset); break;
//        case 2: music.play("2.wav", 20 + startOffset); break;
//        case 3: music.play("3.wav", 17 + startOffset); break;
//        case 4: music.play("4.wav", 61 + startOffset); break;
//        case 5: music.play("5.wav", 40 + startOffset); break;
//        case 6: music.play("6.wav", 50 + startOffset); break;
//        case 7: music.play("7.wav", 50 + startOffset); break;
//    }
//}
