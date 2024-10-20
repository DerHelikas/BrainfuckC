#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BrainFuckUtils.h"
#include "ArgumentSetter.h"

#define BRAINFUCK_INTERPRETATOR_VERSION 2

#define BRAINFUCK_ARRAY_SIZE 30000

#define BRAINFUCK_EXCEPTION_OUTOFRANGE 0
#define BRAINFUCK_EXCEPTION_GIVENNUMBERISNOTVALID 1
#define BRAINFUCK_EXCEPTION_FILEDOESNOTEXIST 2

#define BRAINFUCK_IC_MAJOR_VERSION 1
#define BRIANFUCK_IC_MINOR_VERSION 1
#define BRAINFUCK_IC_PATCH_VERSION 0

#ifdef __linux__
    #define printf_s printf
    #include <unistd.h>

    #define EACCES 13
    #define ENOENT 2
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
    unsigned int ARRsize;
    unsigned int ZonesDeeep;
    
    unsigned char TOTAL_OUTPUT_MODE;
    unsigned char ExecFileCode;

    char * ExecuteArg; 
}Brainfuck_settings;



void BrainFuckInicReading(int Length,  void * commandsPaths[]);

/// @brief It calculates a deep of Brainfuck code.
/// @param code code of brainfuck program
/// @return Deep
int BrainfuckDeepCalculator(const char * code);

/// @brief Checks given brainfuck code.
/// @param code Code
/// @return If code has no syntaxical exeptions, then it will retun 0. Otherwise - 1.
int BrainfuckCodeVerifier(const char * code,Brainfuck_settings BrainfuctDefines);