#ifndef _STRING_
#define _STRING_

#define PARSING_NOT_INT 245

#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <memory.h>

#include "vector.h"

typedef struct {
    uint64_t len;
    char* cstr;
} string;

string _str_from_cstr(const char*);
void _str_push(string*, const char*);
string _str_merge(string*, string*);
string _str_slice(string*, uint64_t, uint64_t);
string _str_clone(string*);
int8_t _str_is_alpha(string*);
int8_t _str_is_numeric(string*);
int32_t _str_parse_i32(string*);
int64_t _str_parse_i64(string*);

string _str_from_cstr(const char* src) {
    string str;
    str.len = 0;
    while (src[str.len++] != 0) { }
    str.cstr = (char*) malloc(str.len);
    memcpy(str.cstr, src, str.len);
    return str;
}

void _str_push(string* dst, const char* src) {
    uint64_t add_size = 0;
    while (src[add_size++] != 0) { }
    char* cp_buf = (char*)malloc(dst->len + add_size);
    memcpy(cp_buf, dst->cstr, dst->len);
    memcpy(cp_buf+dst->len-1, src, add_size);
    free(dst->cstr);
    dst->cstr = cp_buf;
    dst->len += add_size;
}

string _str_merge(string* src1, string* src2) {
    string str;
    str.len = src1->len + src2->len -1;
    str.cstr = (char*)malloc(src1->len + src2->len -1);
    memcpy(str.cstr, src1->cstr, src1->len -1);
    memcpy(str.cstr + src1->len -1, src2->cstr, src2->len);
    return str;
}

string _str_slice(string* src, uint64_t l, uint64_t r) {
    string slice;
    slice.cstr = (char*)malloc(r - l + 1);
    slice.len = r - l;
    memcpy(slice.cstr, src->cstr+l, r - l);
    slice.cstr[r-l] = 0;
    return slice;
}

string _str_clone(string* src) {
    string str;
    str.len = src->len;
    memcpy(str.cstr, src->cstr, str.len);
    return str;
}
int8_t _str_is_alpha(string* str) { // bool
    for (uint64_t i = 0; i < str->len-1; ++i) {
        if (*(str->cstr + i) < 0x41 || *(str->cstr + i) > 0x7A) {
            return 0;
        }
    }
    return 1;
}

int8_t _str_is_numeric(string* str) { // bool
    for (uint64_t i = 0; i < str->len-1; ++i) {
        if (*(str->cstr + i) < 0x30 || *(str->cstr + i) > 0x39) {
            return 0;
        }
    }
    return 1;
}

int32_t _str_parse_i32(string* str) {
    int32_t num = 0;
    for (uint64_t i = 0; i < str->len-1; ++i) {
        num *= 10;
        num += *(str->cstr + i) % 16;
    }
    return num;
}

int64_t _str_parse_i64(string* str) {
    int64_t num = 0;
    for (uint64_t i = 0; i < str->len-1; ++i) {
        num *= 10;
        num += *(str->cstr + i) % 16;
    }
    return num;
}

#endif//_STRING_