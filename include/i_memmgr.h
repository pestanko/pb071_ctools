//
// Created by Peter Stanko on 6/27/16.
//

#ifndef PB071_CTOOLS_I_MEMMGR_H
#define PB071_CTOOLS_I_MEMMGR_H

#ifndef SAVE_ALLOC

#define MEM_ALLOC malloc
#define MEM_REALLOC realloc
#define MEM_FREE free

#else

#define MEM_ALLOC safe_malloc
#define MEM_REALLOC safe_realloc
#define MEM_FREE safe_free

#endif


void savemem_init();
void savemem_clean();



#endif //PB071_CTOOLS_I_MEMMGR_H
