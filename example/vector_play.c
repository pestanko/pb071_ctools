//
// Created by Peter Stanko on 6/27/16.
//

#include <stdio.h>
#include "vector.h"

#define COUNT 3

void free_elems(node_type_t *node, size_t index)
{
    index = index;
    free((*node).ptrAny);
    (*node).ptrAny = NULL;
}


int main(void)
{
    vector_t *vector = vectorCreate();

    for(int i = 0; i < 10; i++) {
        vectorAddAny(vector, malloc(sizeof(10) * 4));
    }

    vectorApply(vector, free_elems);

    for(int i = 0; i < 10; i++) {
        printf("%lu\n", (unsigned long) vector->container[i].value.ptrAny);
    }

    vectorDestroy(vector);
    return 0;
}

