//
// Created by Peter Stanko on 6/23/16.
//



#ifndef PB071_CTOOLS_CHELPERS_H
#define PB071_CTOOLS_CHELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stringNew(size_t size);
char *stringCopy(const char *string);
void stringDelete(char *string);
char *stringJoin(char *pre, char *post);

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


int         strToInt(char *str);
double      strToDouble(char *str);
float       strToFloat(char *str);
char        strToChar(char *str);
unsigned    strToUnsigned(char *str);
long long   strToLong(char *str);

char *      strFromInt(int number);
char *      strFromDouble(double number);
char *      strFromFloat(float number);
char *      strFromChar(char ch);
char *      strFromUnsigned(unsigned number);
char *      strFromLong(long long number);

#endif //PB071_CTOOLS_CHELPERS_H
