#ifndef WAVE_H
#define WAVE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h> 
using namespace std;
	
typedef struct  WAV_HEADER
{
  char riffID[4]; 
  unsigned int size;  
  char wavID[4];  
  char fmtID[4];  
  unsigned int fmtSize; 
  unsigned short format; 
  unsigned short channels; 
  unsigned int sampleRate; 
  unsigned int bytePerSec; 
  unsigned short blockSize; 
  unsigned short bit;  
  char dataID[4]; 
  unsigned int dataSize; 
} wav_hdr;

typedef struct WAVE_DATA {
	wav_hdr wavHeader;
	std::vector<short> lData;
}WAV_DATA;

WAV_DATA readWave(string file);
void writeWave(WAV_DATA wavData, string outfile);
void writeHeader(wav_hdr wavHeader, string file);
void readHeader(wav_hdr &wavHeader, string file);
#endif