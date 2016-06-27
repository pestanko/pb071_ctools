//
// Created by Peter Stanko on 6/23/16.
//


#define TESTING
#define TESTING_MAIN
#include "testing.h"
#include "CHelpers.h"

#define ABS(x) ( (x) < 0 ) ? ( (x) * (-1.0) ) : (x)
#define EPS 0.000001

static int cmp_float(double number, double expected)
{
    if( (ABS( number - expected )) > EPS ) return 0;
    return 1;
}


TEST(strToInt)
{
    int number = strToInt("1234");
    ASSERT(number == 1234);

    number = strToInt("1234.5667");
    ASSERT(number == 1234);
}

TEST(strToFloat)
{
    float number = strToFloat("1234.5667");
    float expected = 1234.5667f;
    ASSERT(cmp_float(number, expected));
}


/*TEST(strToDouble)
{
    double number  = strToDouble("123.44566");
    double expected = 123.44566;
    ASSERT(cmp_float(number, expected));
}*/

TEST(strToLong)
{
    long long number = strToLong("123455566767");
    long long expected = 123455566767ll;

    ASSERT( number == expected);

}

TEST(strToUnsigned)
{
    unsigned number = strToUnsigned("1255566767");
    unsigned expected = 1255566767u;
    ASSERT( number == expected);
}




