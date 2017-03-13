#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma once
#ifndef FILEINPUT_H_IS_INCLUDED
#define FILEINPUT_H_IS_INCLUDED
char *Fgets(char [], int , FILE *);

void RemoveTailControlCode(char []);

void SafeStrCpy(char [], char [], int , int );

int ParseString(int &,	int [],	int [],char [],	int);

#endif // !FILEINPUT_H
