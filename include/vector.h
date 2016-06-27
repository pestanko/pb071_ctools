//
// Created by Peter Stanko on 6/24/16.
//

#ifndef PB071_CTOOLS_VECTOR_H
#define PB071_CTOOLS_VECTOR_H

#include <stdlib.h>

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
} node_type_t;

static node_type_t NONE_VALUE = { .ptrAny = NULL };



enum enum_node_type {
    N_CHAR,
    N_INT,
    N_DOUBLE,
    N_LONG,
    N_FLOAT,
    N_UNSIGNED,

    P_STR,
    P_INT,
    P_DOUBLE,
    P_UNSIGNED,
    P_LONG,
    P_FLOAT,
    P_ANY,
    P_NONE
} ;

typedef struct CVNode{
    enum enum_node_type eType;
    node_type_t value;
} vec_node_t;

typedef struct CVector {
    size_t allocSize;
    size_t size;
    vec_node_t *container;
} vector_t;



vector_t    *vectorCreate();
void        vectorDestroy(vector_t * vec);
void        vectorAdd(vector_t *vec, node_type_t value, enum enum_node_type type);
node_type_t vectorGet(vector_t *vec, size_t index);
void        vectorApply(vector_t *vec, void (*func)(node_type_t *, size_t ));
void        vectorMap(vector_t *vec, void *out,
                        void (*func)(node_type_t *, size_t , void *));


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




#endif //PB071_CTOOLS_VECTOR_H
