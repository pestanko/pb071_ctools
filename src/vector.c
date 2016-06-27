//
// Created by Peter Stanko on 6/25/16.
//

#include "vector.h"
#include <assert.h>

int         vectorValueCompare(value_t v1, value_t v2, enum enum_node_type type)
{

    switch (type)
    {
        case N_INT:
            return v1.numberInteger - v2.numberInteger;
        case N_UNSIGNED:
            return v1.numberUnsigned - v2.numberUnsigned;
        case N_LONG:
            return (int) (v1.numberLong - v2.numberLong);
        case N_FLOAT:
            return  ((int) (v1.numberFloat * 1000)) - ((int) (v2.numberFloat * 1000));
        case N_DOUBLE:
            return  ((int) (v1.numberDouble * 1000)) - ((int) (v2.numberDouble * 1000));

        default:
            return (int) ((size_t) v1.ptrAny - (size_t) v2.ptrAny);
    }
    return 0;
}

vector_t * vectorCreate()
{
    return vectorPrepareSize(4);
}

vector_t *vectorCreateSize(size_t size)
{
    vector_t *vec = vectorPrepareSize(size * 2);
    vec->size = size;
    for(size_t i = 0; i < size; i++)
    {
        vec->container[i].eType = P_NONE;
        vec->container[i].value = NONE_VALUE;
    }
    return vec;
}

vector_t *vectorPrepareSize(size_t size)
{
    vector_t *vec = malloc(sizeof(vector_t));
    vec->size = 0;
    vec->allocSize = size;
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


void vectorApply(vector_t *vec, void (*func)(value_t *, size_t))
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
                      void (*func)(value_t *, size_t, void *))
{
    if(!vec || !func) {
        return;
    }

    for(size_t i = 0; i < vec->size; i++)
    {
        func(&(vec->container[i].value), i, out);
    }
}


void vectorAdd(vector_t *vec, value_t value, enum enum_node_type type)
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


void        vectorSet(vector_t *vec, size_t index, value_t value, enum enum_node_type type)
{
    if(!vec) return;
    if(index >= vec->size) return;

    vec->container[index].value = value;
    vec->container[index].eType = type;

}



void vectorAddInt(vector_t *vec, int value)
{
    value_t node;
    node.numberInteger = value;
    vectorAdd(vec, node, N_INT);
}


void vectorAddDouble(vector_t *vec, double value)
{
    value_t node;
    node.numberDouble = value;
    vectorAdd(vec, node, N_DOUBLE);
}

void vectorAddUnsigned(vector_t *vec, unsigned value)
{
    value_t node;
    node.numberUnsigned = value;
    vectorAdd(vec, node, N_UNSIGNED);
}

void vectorAddLongLong(vector_t *vec, long long value)
{
    value_t node;
    node.numberLong = value;
    vectorAdd(vec, node, N_LONG);
}

void vectorAddString(vector_t *vec, char *value)
{
    value_t node;
    node.string = value;
    vectorAdd(vec, node, P_STR);
}

void vectorAddAny(vector_t *vec, void *value)
{
    value_t node;
    node.ptrAny = value;
    vectorAdd(vec, node, P_ANY);
}


value_t vectorGet(vector_t *vec, size_t index)
{
    if(!vec)
        return NONE_VALUE;
    if(index >= vec->size)
        return NONE_VALUE;

    return vec->container[index].value;
}




int         vectorGetInt(vector_t *vec, size_t index)
{
    value_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0 : res.numberInteger;
}

double      vectorGetDouble(vector_t *vec, size_t index)
{
    value_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0.0 : res.numberDouble;
}

unsigned    vectorGetUnsigned(vector_t *vec, size_t index)
{
    value_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? 0 : res.numberUnsigned;
}

char        *vectorGetString(vector_t *vec, size_t index)
{
    value_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? NULL : res.string;
}

void        *vectorGetAny(vector_t *vec, size_t index)
{
    value_t res = vectorGet(vec, index);
    return (res.ptrAny == NONE_VALUE.ptrAny) ? NULL : res.ptrAny;
}


size_t      vectorFindPos(vector_t *vec, value_t value)
{
    for(size_t i = 0; i < vec->size; i++)
    {
        vec_node_t item = vec->container[i];
        if(vectorValueCompare(item.value, value, item.eType) == 0)
            return i;
    }
    return (size_t) -1;
}

vec_node_t  *vectorFind(vector_t *vec, value_t value)
{
    size_t res = vectorFindPos(vec, value);
   if( res == ((size_t) (-1)))
   {
       return NULL;
   }
    return &(vec->container[res]);
}

void        vectorDelete(vector_t *vec, value_t value)
{
    vec_node_t *node = vectorFind(vec, value);
    if(node)
    {
        node->value = NONE_VALUE;
        node->eType = P_NONE;
    }
}

void        vectorDeletePos(vector_t *vec, size_t pos)
{
    vectorSet(vec, pos, NONE_VALUE, P_NONE);
}

vector_t    *vectorJoin(vector_t *first, vector_t *second)
{
    size_t size = first->size + second->size;
    vector_t *vector = vectorPrepareSize(size + 4);
    assert(vector);
    vector->size = size;

    for(size_t i = 0; i < first->size; i++)
    {
        vector->container[i] = first->container[i];
    }

    for(size_t i = 0, j = first->size; i < second->size; i++, j++)
    {
        vector->container[j] = second->container[i];
    }

    return vector;
}
