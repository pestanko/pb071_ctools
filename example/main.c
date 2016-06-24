//
// Created by Peter Stanko on 6/23/16.
//


#include "CHelpers.h"

int main(void)
{
    printf("Write line: ");
    char * line = readLine();

    printf("\nWrite integer: ");
    int numberInteger = readInt();

    printf("\nWrite unsigned: ");
    unsigned numberUnsigned = readUnsigned();

    printf("\nWrite double: ");
    double numberDouble = readDouble();

    printf("\nWrite float: ");
    float numberFloat = readFloat();

    printf("\nWrite long long: ");
    long long numberLong = readLong();


    printf("Inserted line: %s\n", line);
    printf("Inserted integer: %d\n", numberInteger);
    printf("Inserted unsigned: %u\n", numberUnsigned);
    printf("Inserted double: %lf\n", numberDouble);
    printf("Inserted float: %.3f\n", numberFloat);
    printf("Inserted long long: %lld\n", numberLong);


    free(line);
    return 0;
}

