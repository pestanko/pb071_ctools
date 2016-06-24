//
// Created by Peter Stanko on 6/23/16.
//

#include <malloc.h>
#include "CHelpers.h"


char *fileReadLine(FILE *file)
{

    if (!file) return NULL;
    unsigned long alloc = 32;
    char *line = malloc(sizeof(char) * (alloc + 1));
    if (!line) return NULL;
    int c = 0;

    size_t i = 0;
    while ((c = fgetc(file)) != '\n' && c != EOF) {
        line[i++] = (char) c;
        if ((i + 2) >= alloc) {
            alloc *= 2;
            line = realloc(line, (alloc + 1) * sizeof(char));
            if (*line == NULL) return NULL;
        }
    }
    line[i] = '\0';

    return  line;
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
};

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


int         stringReadInt(char *str)
{
    int number = 0;
    sscanf(str, "%d", &number);
    return number;
}

double      stringReadDouble(char *str)
{
    double number = 0;
    sscanf(str, "%Lf", &number);
    return number;
}

float       stringReadFloat(char *str)
{
    float number = 0;
    sscanf(str, "%f", &number);
    return number;
}

char        stringReadChar(char *str)
{
    if(!str) return '\0';
    return str[0];
}

unsigned    stringReadUnsigned(char *str)
{
    unsigned number = 0;
    sscanf(str, "%u", &number);
    return number;
}

long long   stringReadLong(char *str)
{
    long long number = 0;
    sscanf(str, "%lld", &number);
    return number;
}










