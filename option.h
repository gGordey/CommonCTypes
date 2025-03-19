#ifndef _C_OPTION_
#define _C_OPTION_

#include <stdint.h>
#include <memory.h>
#include <malloc.h>

typedef struct {
    int8_t has_value;
    uint16_t byte_len;
    void* value;
} option;

option _opt_new(int8_t, uint16_t);
void _opt_set_value(option*, void*);

#endif//_C_OPTION