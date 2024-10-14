#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BRAINFUCK_INTERPRETATOR_VERSION 2

#define BRAINFUCK_ARRAY_SIZE 30000

#define BRAINFUCK_EXCEPTION_OUTOFRANGE 0
#define BRAINFUCK_EXCEPTION_GIVENNUMBERISNOTVALID 1
#define BRAINFUCK_EXCEPTION_FILEDOESNOTEXIST 2

#ifdef __linux__
    #define printf_s printf
    #include <unistd.h>
#endif

#ifdef __WIN32
    // Thanks to https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
    #include <io.h>
    #define F_OK 0
    #define access _access
#endif



typedef struct Brainfuck_settings{
    int UseASCII;
    int UseSpaces;
    unsigned int ZonesDeeep;
    unsigned char TOTAL_OUTPUT_MODE;
}Brainfuck_settings;



void BrainFuckInicReading(int Length, const char * commandsPaths[]);