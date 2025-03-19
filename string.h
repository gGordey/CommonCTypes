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
char* _str_slice_to_cstr(string*, uint64_t, uint64_t);
char* _str_cstr_slice_to_cstr(const char*, uint64_t, uint64_t);
string _str_clone(string*);
int8_t _str_is_alpha(string*); // bool
int8_t _str_is_numeric(string*); // bool
int32_t _str_parse_i32(string*);
int64_t _str_parse_i64(string*);
void _str_free(string*);
uint64_t _str_size_cstr(const char*);
int8_t _str_string_eql_string(string*, string*); // bool
int8_t _str_string_eql_cstr(string*, const char*); // bool
int8_t _str_cstr_eql_cstr(const char*, const char*); // bool

#endif//_STRING_