//
// Created by Peter Stanko on 6/25/16.
//

#include "vector.h"
#include <assert.h>

vector_t * vectorCreate()
{
    vector_t *vec = malloc(sizeof(vector_t));
    vec->size = 0;
    vec->allocSize = 4;
    vec->container = (vec_node_t *) malloc(sizeof(vec_node_t) * vec->allocSize);
    assert(vec->container);
    return vec;
}


void vectorDestroy(vector_t * vec)
{
    vec->size = 0;
    vec->allocSize = 0;
    free(vec->container);
    free(vec);
}


void vectorApply(vector_t *vec, void (*func)(node_type_t *, size_t))
{
    if(!vec || !func){
        return;
    }

    for(size_t i = 0; i < vec->size; i++)
    {
        func(&(vec->container[i].value), i);
    }
}

void        vectorMap(vector_t *vec, void *out,
                      void (*func)(node_type_t *, size_t, void *))
{
    if(!vec || !func) {
        return;
    }

    for(size_t i = 0; i < vec->size; i++)
    {
        func(&(vec->container[i].value), i, out);
    }
}


void vectorAdd(vector_t *vec, node_type_t value, enum enum_node_type type)
{
    if(!vec) return;

    if((vec->size + 1)  >= vec->allocSize)
    {
        vec->allocSize *= 2;
        vec->container = (vec_node_t*) realloc(vec->container, sizeof(vec_node_t) * vec->allocSize);
        assert(vec->container);
    }

    vec->container[vec->size].eType = type;
    vec->container[vec->size].value = value;
    (vec->size)++;
}


void vectorAddInt(vector_t *vec, int value)
{
    node_type_t node;
    node.numberInteger = value;
    vectorAdd(vec, node, N_INT);
}


void vectorAddDouble(vector_t *vec, double value)
{
    node_type_t node;
    node.numberDouble = value;
    vectorAdd(vec, node, N_DOUBLE);
}

void vectorAddUnsigned(vector_t *vec, unsigned value)
{
    node_type_t node;
    node.numberUnsigned = value;
    vectorAdd(vec, node, N_UNSIGNED);
}

void vectorAddLongLong(vector_t *vec, long long value)
{
    node_type_t node;
    node.numberLong = value;
    vectorAdd(vec, node, N_LONG);
}

void vectorAddString(vector_t *vec, char *value)
{
    node_type_t node;
    node.string = value;
    vectorAdd(vec, node, P_STR);
}

void vectorAddAny(vector_t *vec, void *value)
{
    node_type_t node;
    node.ptrAny = value;
    vectorAdd(vec, node, P_ANY);
}


node_type_t vectorGet(vector_t *vec, size_t index)
{
    if(!vec)
        return NONE_VALUE;
    if(index >= vec->size)
        return NONE_VALUE;

    return vec->container[index].value;
}




int         vectorGetInt(vector_t *vec, size_t index)
{
    node_type_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0 : res.numberInteger;
}

double      vectorGetDouble(vector_t *vec, size_t index)
{
    node_type_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0.0 : res.numberDouble;
}

unsigned    vectorGetUnsigned(vector_t *vec, size_t index)
{
    node_type_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0 : res.numberUnsigned;
}

char        *vectorGetString(vector_t *vec, size_t index)
{
    node_type_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? NULL : res.string;
}

void        *vectorGetAny(vector_t *vec, size_t index)
{
    node_type_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? NULL : res.ptrAny;
}
