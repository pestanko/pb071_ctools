//
// Created by Peter Stanko on 6/23/16.
//



#ifndef PB071_CTOOLS_CHELPERS_H
#define PB071_CTOOLS_CHELPERS_H

#include <stdio.h>
#include <stdlib.h>


char        *fileReadLine(FILE* file);
int         fileReadInt(FILE *file);
double      fileReadDouble(FILE *file);
float       fileReadFloat(FILE *file);
char        fileReadChar(FILE *file);
unsigned    fileReadUnsigned(FILE *file);
long long   fileReadLong(FILE * file);


char        *readLine();
int         readInt();
double      readDouble();
float       readFloat();
char        readChar();
unsigned    readUnsigned();
long long   readLong();


int         stringReadInt(char *str);
double      stringReadDouble(char *str);
float       stringReadFloat(char *str);
char        stringReadChar(char *str);
unsigned    stringReadUnsigned(char *str);
long long   stringReadLong(char *str);



#endif //PB071_CTOOLS_CHELPERS_H
