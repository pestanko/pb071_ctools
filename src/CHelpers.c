//
// Created by Peter Stanko on 6/23/16.
//

#include <stdlib.h>
#include "CHelpers.h"
#include "i_memmgr.h"

#define UNUSED(a) (a) = (a)


void stringDelete(char *string)
{
    MEM_FREE(string);
}

char *stringNew(size_t size)
{
    return (char*) MEM_ALLOC(sizeof(char) * (size + 1));
}

char *stringCopy(const char *string)
{
    if(!string){
        return NULL;
    }

    char *nString = stringNew(strlen(string));
    strcpy(nString, string);

    return nString;
}


char *fileReadLine(FILE *file)
{

    if (!file) {return NULL;}
    unsigned long alloc = 32;
    char *line = (char*) MEM_ALLOC(sizeof(char) * (alloc + 1));
    if (!line) {return NULL;}
    int c = 0;

    size_t i = 0;
    while ((c = fgetc(file)) != '\n' && c != EOF) {
        line[i++] = (char) c;
        if ((i + 2) >= alloc) {
            alloc *= 2;
            line = MEM_REALLOC(line, (alloc + 1) * sizeof(char));
            if (line == NULL) return NULL;
        }
    }
    line[i] = '\0';

    return  line;
}

char *stringJoin(char *pre, char *post)
{
    size_t len = strlen(pre) + strlen(post) + 1;
    char *nString = stringNew(len);
    strcpy(nString, pre);
    strcat(nString, post);
    return nString;
}



int fileReadInt(FILE *file)
{
    if(!file) return 0;

    int number = 0;
    fscanf(file, "%d", &number);
    return number;
}


double fileReadDouble(FILE *file)
{
    if(!file) return 0;

    double number = 0;
    fscanf(file, "%lf", &number);
    return number;
}


float fileReadFloat(FILE *file)
{
    if(!file) return 0;

    float number = 0;
    fscanf(file, "%f", &number);
    return number;
}


char fileReadChar(FILE *file)
{
    return (char) fgetc(file);
}



unsigned fileReadUnsigned(FILE *file)
{
    if(!file) return 0;

    unsigned number = 0;
    fscanf(file, "%u", &number);
    return number;
}


long long  fileReadLong(FILE * file)
{
    if(!file) return 0;

    long long number = 0;
    fscanf(file, "%lld", &number);
    return number;
}

char *readLine()
{
    return fileReadLine(stdin);
}

int readInt()
{
    return fileReadInt(stdin);
}

float readFloat()
{
    return fileReadFloat(stdin);
}

double readDouble()
{
    return fileReadDouble(stdin);
}

char readChar() {
    return fileReadChar(stdin);
}

unsigned readUnsigned() {
    return fileReadUnsigned(stdin);
}

long long readLong()
{
    return fileReadLong(stdin);
}


int         strToInt(char *str)
{
    int number = 0;
    sscanf(str, "%d", &number);
    return number;
}

double      strToDouble(char *str)
{
    double number = 0;
    sscanf(str, "%lf", &number);
    return number;
}

float       strToFloat(char *str)
{
    float number = 0;
    sscanf(str, "%f", &number);
    return number;
}

char        strToChar(char *str)
{
    if(!str) return '\0';
    return str[0];
}

unsigned    strToUnsigned(char *str)
{
    unsigned number = 0;
    sscanf(str, "%u", &number);
    return number;
}

long long   strToLong(char *str)
{
    long long number = 0;
    sscanf(str, "%lld", &number);
    return number;
}


char *      strFromInt(int number)
{
    char *str = stringNew(15);
    sprintf(str, "%d", number);
    return str;
}

char *      strFromDouble(double number)
{
    char *str = stringNew(30);
    sprintf(str, "%lf", number);
    return str;
}

char *      strFromFloat(float number)
{
    char *str = stringNew(15);
    sprintf(str, "%f", number);
    return str;
}

char *      strFromChar(char ch)
{
    char *str = stringNew(2);
    sprintf(str, "%c", ch);
    return str;
}

char *      strFromUnsigned(unsigned number)
{
    char *str = stringNew(15);
    sprintf(str, "%u", number);
    return str;
}

char *      strFromLong(long long number)
{
    char *str = stringNew(20);
    sprintf(str, "%lld", number);
    return str;
}





