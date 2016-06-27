//
// Created by Peter Stanko on 6/27/16.
//


#include "i_memmgr.h"
#include "vector.h"

vector_t *intern_pointerTable = NULL;


void safe_free(void *ptr)
{
    UNUSED(ptr);
}

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    vectorAddAny(intern_pointerTable, ptr);
    return ptr;
}


void *safe_realloc(void *ptr, size_t size)
{
    void *newp = realloc(ptr, size);
    vectorAddAny(intern_pointerTable, ptr);
    return newp;
}


void internFree(value_t * val)
{
    free(val->ptrAny);
    val->ptrAny = NULL;
}

void savemem_clean()
{
    vectorApply(intern_pointerTable, internFree);
    vectorDestroy(intern_pointerTable);
}

void savemem_init()
{
    if(intern_pointerTable)
    {
        savemem_clean();
    }

    intern_pointerTable = vectorCreate();
}



