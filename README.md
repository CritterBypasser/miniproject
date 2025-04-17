# miniproject
This code is to integrate an SD card reader module, with an Arduino Nano and an amplifier module which is connected to a speaker.
The connections are:
* amplifier input (only one side as audio in SD card is mono, not stereo) from D9
* sd card vcc to Arduino Nano 5v output
* sd card ground to gnd
* sd card MISO to D12
* sd card MOSI to D11
* sd card SCK to D13
* sd card CS to D10

audio has to be previously written onto the SD card in .wav format
