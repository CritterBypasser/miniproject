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
//pinMode(4, INPUT_PULLUP); //Pull up for play/pause switch
////pinMode(3, INPUT_PULLUP); //Pull up for fast forward
//music.setVolume(5); // 0 to 7. Set volume level
//music.quality(1); // Set 1 for 2x oversampling Set 0 for normal
//}
//
//void loop()
//{
//button1 = digitalRead(2);
//button2 = digitalRead(4);
//Serial.println(button1);
//Serial.println(button2);
//
//if (button2== LOW) //Button 2 Pressed
//{
//Serial.println("PLAY / PAUSE");
//music.pause();
//Serial.println("ok");
//}
//
//if (button1 == LOW) //Button 1 Pressed
//{
//song_number++;
//if (song_number==7)
//{song_number=1;}
//
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
//
#include "SD.h"      // SD card library
#include "TMRpcm.h"  // Audio File Library
#include "SPI.h"     // SPI library for SD card

#define SD_ChipSelectPin 10

TMRpcm music;
int button1, button2;
int song_number = 1;

void setup()
{
    music.speakerPin = 9; // Audio output pin
    Serial.begin(9600);

    Serial.print("Initializing SD Card...");
    if (!SD.begin(10)) {
        Serial.println(" SD Initialization Failed!");
        while (1); // Stop execution if SD fails
    }
    Serial.println(" SD Card Initialized Successfully!");

    pinMode(2, INPUT_PULLUP); // Next track button
    pinMode(3, INPUT_PULLUP); // Play/pause button

    music.setVolume(5); // Volume level 0-7
    music.quality(1);   // Set 1 for 2x oversampling, 0 for normal
}

void loop()
{
    button1 = digitalRead(2);
    button2 = digitalRead(4);
    delay(50);  // Button debounce

    if (button2 == LOW) // Play/Pause
    {
        if (music.isPlaying()) {
            Serial.println("Pausing...");
            music.pause();
        } else {
            Serial.println("Resuming...");
            playSong(song_number);
        }
        delay(300);
    }

    if (button1 == LOW) // Change Song
    {
        song_number++;
        if (song_number == 7) { song_number = 1; }
        playSong(song_number);
        delay(300);
    }
}

void playSong(int song_number)
{
    switch (song_number) {
        case 1: music.play("1.wav", 25); break;
        case 2: music.play("2.wav", 20); break;
        case 3: music.play("3.wav", 15); break;
        case 4: music.play("4.wav", 71); break;
        case 5: music.play("5.wav"); break;
        case 6: music.play("6.wav", 58); break;
    }
}
