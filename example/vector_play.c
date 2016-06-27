//
// Created by Peter Stanko on 6/27/16.
//

#include <stdio.h>
#include "vector.h"

#define COUNT 3

void free_elems(value_t *node, size_t index)
{
    index = index;
    free((*node).ptrAny);
    (*node).ptrAny = NULL;
}



int main(void)
{
    vector_t *vector = vectorCreateSize(10);


    printf("SIZE: %lu", vector->size);
    printf("\tALLOC_SIZE: %lu\n",vector->allocSize);

    for(int i = 0; i < 10; i++)
    {
      vectorValueCompare(NONE_VALUE, vector->container[i].value, P_NONE);
        vector->container[i].eType;
    }

    vectorDestroy(vector);
    return 0;
}

