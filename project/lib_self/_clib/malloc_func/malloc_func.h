#ifndef __MALLOC_FUNC_
#define __MALLOC_FUNC_


#ifdef __cplusplus
extern "C"{
#endif

#include <stddef.h>


void* malloc_func(size_t _Size);

void free_func(void *_Memory);



#ifdef __cplusplus
}
#endif



#endif
