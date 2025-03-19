#ifndef _C_VECTOR_
#define _C_VECTOR_

#include <memory.h>
#include <malloc.h>
#include <stdlib.h>

#define EXIT_INVALID_ALLOCATON 214

typedef struct {
    size_t cap;
    size_t byte_len;
    size_t size;
    void* start;
} vector;

vector _cvec_new(size_t);
vector _cvec_new_filled(size_t, size_t, const void*);
void _cvec_fill(vector*, const void*);
void _cvec_clear(vector*);
void _cvec_free(vector* vec);
void _cvec_push(vector*, const void*);
void _cvec_pop(vector*);
void _cvec_reserve(vector*, size_t);
void* _cvec_at(vector*, size_t);
void _cvec_realloc(vector*);
void _cvec_reverse(vector*);
void _cvec_remove(vector*, size_t);
void _cvec_insert(vector*, const void*, size_t);
vector _cvec_clone(vector*);

#endif // _C_VECTOR_