//
// Created by Peter Stanko on 6/23/16.
//


#define TESTING
#define TESTING_MAIN
#include "testing.h"
#include "CHelpers.h"

TEST(stringReadInt)
{
    int number = stringReadInt("1234");
    ASSERT(number == 1234);

    number = stringReadInt("1234.5667");
    ASSERT(number == 1234);
}

TEST(stringReadFloat)
{
    float number = stringReadFloat("1234.5667");
    ASSERT(number == 1234.5667);
}


TEST(stringReadDouble)
{
    double number  = stringReadDouble("123.4456632342323323232");
    ASSERT( ((int) (number*1000)) == 123445 );
}

TEST(stringReadLong)
{
    long long number = stringReadLong("123455566767");

    ASSERT( number == 123455566767 );
}

TEST(stringReadUnsigned)
{
    unsigned number = stringReadUnsigned("1255566767");

    ASSERT( number == 1255566767);
}

