//
// Created by Peter Stanko on 6/25/16.
//

#define TESTING
#define TESTING_MAIN
#include "testing.h"

#include "testing.h"
#include "CHelpers.h"
#include "vector.h"


#define ABS(x) ( (x) < 0 ) ? ( (x) * (-1.0) ) : (x)
#define EPS 0.000001

static int cmp_float(double number, double expected)
{
    if( (ABS( number - expected )) > EPS ) return 0;
    return 1;
}




TEST(vectorCreate)
{
    vector_t *vector = vectorCreate();
    ASSERT(vector);
    ASSERT(vector->container);
    ASSERT(vector->size == 0);
    ASSERT(vector->allocSize = 4);
    vectorDestroy(vector);
}


TEST(vectorAdd)
{
    vector_t *vector = vectorCreate();

    node_type_t value;
    value.numberInteger = 1;
    vectorAdd(vector, value, N_INT);
    ASSERT(vector->container);
    ASSERT(vector->container[0].value.numberInteger == 1);
    ASSERT(vector->container[0].eType == N_INT);

    value.numberInteger = 2;
    vectorAdd(vector, value, N_INT);
    ASSERT(vector->container[1].value.numberInteger == 2);
    ASSERT(vector->container[1].eType == N_INT);

    value.numberFloat = 3.0;
    vectorAdd(vector, value, N_FLOAT);
    ASSERT(cmp_float(vector->container[2].value.numberFloat, 3.0));
    ASSERT(vector->container[2].eType == N_FLOAT);


    value.numberFloat = 4.0;
    vectorAdd(vector, value, N_FLOAT);
    ASSERT(cmp_float(vector->container[3].value.numberFloat, 4.0));
    ASSERT(vector->container[3].eType == N_FLOAT);

    value.numberLong = 5L;
    vectorAdd(vector, value, N_LONG);
    ASSERT(vector->container);
    ASSERT(vector->container[0].value.numberInteger == 1);
    ASSERT(vector->container[0].eType == N_INT);
    ASSERT(vector->container[4].value.numberLong == 5);
    ASSERT(vector->container[4].eType == N_LONG);

    vectorDestroy(vector);
}


TEST(vectorGet)
{
    vector_t *vector = vectorCreate();
    node_type_t value;
    value.numberInteger = 1;
    vectorAdd(vector, value, N_INT);

    node_type_t res = vectorGet(vector, 0);
    ASSERT(res.numberInteger == 1);

    value.numberUnsigned = 2;
    vectorAdd(vector, value, N_UNSIGNED);

    res = vectorGet(vector, 1);
    ASSERT(res.numberUnsigned == 2);

    ASSERT(vectorGet(vector, 100).ptrAny == NONE_VALUE.ptrAny);


    vectorDestroy(vector);
}

TEST(addGetType)
{
    vector_t *vector = vectorCreate();

    vectorAddInt(vector, 1);
    ASSERT(vectorGetInt(vector, 0) == 1);

    vectorAddDouble(vector, 2.0);
    ASSERT(cmp_float(vectorGetDouble(vector, 1), 2.0));

    char string[] = "ahoj svet";

    vectorAddString(vector, string);
    ASSERT(vectorGetString(vector, 2) == string);

    ASSERT(vectorGetAny(vector, 100) == NULL);

    vectorDestroy(vector);
}


void free_elems(node_type_t *node, size_t index)
{
    index = index;
    free((*node).ptrAny);
    (*node).ptrAny = NULL;
}

TEST(vectorApply)
{
    vector_t *vector = vectorCreate();

    for(int i = 0; i < 10; i++) {
        vectorAddAny(vector, malloc(sizeof(10) * 4));
    }

    vectorApply(vector, free_elems);

    for(int i = 0; i < 10; i++) {
        ASSERT(vector->container[i].value.ptrAny == NULL);
    }

    vectorDestroy(vector);
}

void vector_sum(node_type_t *node, size_t index, void * out)
{
    *((int*) out) += node->numberInteger;

}


TEST(vectorMap)
{
    vector_t *vector = vectorCreate();

    for(int i = 1; i <= 10; i++) {
        vectorAddInt(vector, i);
    }

    int out = 0;

    vectorMap(vector, &out, vector_sum);

    ASSERT(out == 55);

    vectorDestroy(vector);
}