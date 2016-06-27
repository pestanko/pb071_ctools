//
// Created by Peter Stanko on 6/24/16.
//

#ifndef PB071_CTOOLS_VECTOR_H
#define PB071_CTOOLS_VECTOR_H

#include <stdlib.h>

#define UNION_CMP(a, b) (a).numberLong - (b).numberLong


typedef union CNode_type {
    char        character;
    int         numberInteger;
    double      numberDouble;
    long long   numberLong;
    unsigned    numberUnsigned;
    float       numberFloat;

    char        *string;
    int         *ptrInteger;
    double      *ptrDouble;
    unsigned    *ptrUnsigned;
    long long   *prtLong;
    float       *ptrFloat;
    void        *ptrAny;
} value_t;

static value_t NONE_VALUE = { .ptrAny = NULL };



enum enum_node_type {
    P_NONE = 0,
    N_CHAR = 1,
    N_INT = 2,
    N_DOUBLE = 3,
    N_LONG = 4,
    N_FLOAT = 5,
    N_UNSIGNED = 6,

    P_STR = 10,
    P_INT = 11,
    P_DOUBLE = 12,
    P_UNSIGNED = 13,
    P_LONG = 14,
    P_FLOAT = 15,
    P_ANY = 100
} ;

typedef struct CVNode{
    enum enum_node_type eType;
    value_t value;
} vec_node_t;

typedef struct CVector {
    size_t allocSize;
    size_t size;
    vec_node_t *container;
} vector_t;



vector_t    *vectorCreate();
vector_t    *vectorCreateSize(size_t size);
vector_t    *vectorPrepareSize(size_t size);
void        vectorDestroy(vector_t * vec);
void        vectorAdd(vector_t *vec, value_t value, enum enum_node_type type);
value_t     vectorGet(vector_t *vec, size_t index);
void        vectorSet(vector_t *vec, size_t index, value_t value, enum enum_node_type type);
void        vectorApply(vector_t *vec, void (*func)(value_t *, size_t ));
void        vectorMap(vector_t *vec, void *out,
                        void (*func)(value_t *, size_t , void *));

vec_node_t  *vectorFind(vector_t *vec, value_t value);
size_t      vectorFindPos(vector_t *vec, value_t value);
void        vectorDelete(vector_t *vec, value_t value);
void        vectorDeletePos(vector_t *vec, size_t pos);
vector_t    *vectorJoin(vector_t *first, vector_t *second);


int         vectorGetInt(vector_t *vec, size_t index);
double      vectorGetDouble(vector_t *vec, size_t index);
unsigned    vectorGetUnsigned(vector_t *vec, size_t index);
char        *vectorGetString(vector_t *vec, size_t index);
void        *vectorGetAny(vector_t *vec, size_t index);


void        vectorAddInt(vector_t *vec, int value);
void        vectorAddDouble(vector_t *vec, double value);
void        vectorAddUnsigned(vector_t *vec, unsigned value);
void        vectorAddLongLong(vector_t *vec, long long value);
void        vectorAddString(vector_t *vec, char *value);
void        vectorAddAny(vector_t *vec, void *value);

int         vectorValueCompare(value_t v1, value_t v2, enum enum_node_type type);




#endif //PB071_CTOOLS_VECTOR_H
