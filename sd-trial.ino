//#include <SPI.h>
//#include <SD.h>
//
//#define SD_CS 15  // CS pin connected to GPIO15
//
//void readFile(const char *path) {
//    Serial.println("Reading file");
//    File file = SD.open(path);
//    if (!file) {
//        Serial.println("Failed to open file for reading!");
//        return;
//    }
//
//    Serial.println("File Content:");
//    while (file.available()) {
//        Serial.write(file.read());
//    }
//    Serial.println();
//    file.close();
//}
//
//void setup() {
//    Serial.begin(115200);
//    Serial.println("\nInitializing SD card...");
//
//    if (!SD.begin(SD_CS)) {
//        Serial.println("SD Card initialization failed!");
//        return;
//    }
//
//    Serial.println("SD Card initialized successfully.");
//    readFile("rumo-ao-sol-13162.wav");  // Change this to the file you want to read
//}
//
//void loop() {
//      if (!SD.begin(SD_CS)) {
//        Serial.println("SD Card initialization failed!");
//        return;
//    }
//}


//SD Card Interface code for ESP32
//  SPI Pins of ESP32 SD card as follows:
//  CS    = 5;
//  MOSI  = 23;
//  MISO  = 19;
//  SCK   = 18;
#include <SPI.h>
#include <SD.h>

File myFile;
const int CS = 5;

void WriteFile(const char * path, const char * message){
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open(path, FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.printf("Writing to %s ", path);
    myFile.println(message);
    myFile.close(); // close the file:
    Serial.println("completed.");
  } 
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening file ");
    Serial.println(path);
  }
}


void ReadFile(const char * path){
  // open the file for reading:
  myFile = SD.open(path);
  if (myFile) {
     Serial.printf("Reading file from %s\n", path);
     // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close(); // close the file:
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void setup() {
  Serial.begin(9600);    // Set serial baud rate to 9600
  delay(500);
  while (!Serial) { ; }  // wait for serial port to connect. Needed for native USB port only
  Serial.println("Initializing SD card...");
  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  WriteFile("rumo-ao-sol-13162.wav");
  ReadFile("rumo-ao-sol-13162.wav");
}

void loop() {
  // nothing happens after setup
}
