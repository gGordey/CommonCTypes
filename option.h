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

option _opt_new(int8_t has_halue, uint16_t byte_len) {
    option opt;
    opt.has_value = has_halue;
    opt.byte_len = byte_len;
    opt.value = malloc(byte_len);
    return opt;
}

void _opt_set_value(option* opt, void* value) {
    memcpy(opt->value, value, opt->byte_len);
}

#endif//_C_OPTION