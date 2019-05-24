#ifndef MOONBOT_WT2003S_MP3_H
#define MOONBOT_WT2003S_MP3_H

#include "Arduino.h"
#include <SoftwareSerial.h>

#define MP3_NUM_CMD_BYTES 11
#define MP3_NUM_NAME_BYTES 9

//These are the commands that are sent over serial to the WT2003S
#define MP3_COMMAND_PLAY_INDEX_IN_ROOT 0xA2
#define MP3_COMMAND_PLAY_FILE_IN_ROOT 0xA3
#define MP3_COMMAND_PLAY_INDEX_IN_FOLDER 0xA4
#define MP3_COMMAND_PLAY_FILE_IN_FOLDER 0xA5
#define MP3_COMMAND_PAUSE 0xAA
#define MP3_COMMAND_STOP 0xAB
#define MP3_COMMAND_NEXT 0xAC
#define MP3_COMMAND_PREVIOUS 0xAD
#define MP3_COMMAND_SET_VOLUME 0xAE //Can take more than 150ms to complete
#define MP3_COMMAND_SET_EQ_MODE 0xB2

#define MP3_COMMAND_GET_VOLUME 0xC1
#define MP3_COMMAND_GET_CURRENT_STATE 0xC2
#define MP3_COMMAND_GET_SONG_COUNT 0xC5
#define MP3_COMMAND_GET_SONGS_IN_FOLDER_COUNT 0xC6
#define MP3_COMMAND_GET_FILE_PLAYING 0xC9
#define MP3_COMMAND_GET_SONG_NAME_PLAYING 0xCB

#define MP3_START_CODE 0x7E
#define MP3_END_CODE 0xEF

class WT2003S {
 private:
  void sendCommandHW(uint8_t commandLength);
  void sendCommandSW(uint8_t commandLength);

 protected:
  HardwareSerial *_hwSerialPort;
  SoftwareSerial *_swSerialPort;
  uint8_t _busyPin;

 public:
  uint8_t commandBytes[MP3_NUM_CMD_BYTES];
  uint8_t songName[MP3_NUM_NAME_BYTES];

  WT2003S();

  void begin(SoftwareSerial &serialPort);
  void begin(HardwareSerial &serialPort = Serial);

  uint8_t play(char* fileName);
  uint8_t setVolume(uint8_t volumeLevel);
  uint8_t stop(void);
  void pause(void);
  bool isPlaying(void);
  uint8_t playPrevious(void);
  uint8_t playNext(void);

  uint8_t setPlayMode(uint8_t mode);
  uint16_t getSongCount(void);
  void getSongName();
  uint8_t playTrackNumber(uint8_t trackNumber);
  uint8_t getVolume(void);
  uint8_t setEQ(uint8_t eqType);
  uint8_t getPlayStatus(void);

  void sendCommand(uint8_t commandLength);
  uint8_t getResponse(void);
  uint16_t getTwoByteResponse(void);
  bool responseAvailable(void);
  void clearBuffer(void);
};

#endif
//Added by Sloeber 
#pragma once