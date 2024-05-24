#include "malloc_func.h"

#include <stdlib.h>



void* malloc_func(size_t _Size)
{
    return malloc(_Size);
}


void free_func(void *_Memory)
{
    free(_Memory);
    _Memory = NULL;
}


