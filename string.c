#include "string.h"


string _str_from_cstr(const char* src) {
    string str;
    str.len = _str_size_cstr(src);
    str.cstr = (char*) malloc(str.len);
    memcpy(str.cstr, src, str.len);
    return str;
}

void _str_push(string* dst, const char* src) {
    uint64_t add_size = _str_size_cstr(src);
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
    slice.len = r - l;
    slice.cstr = _str_cstr_slice_to_cstr(src->cstr, l, r);
    return slice;
}

char* _str_slice_to_cstr(string* src, uint64_t l, uint64_t r) {
    return _str_cstr_slice_to_cstr(src->cstr, l, r);
}

char* _str_cstr_slice_to_cstr(const char* src, uint64_t l, uint64_t r) {
    char* res = (char*) malloc(r - l);
    memcpy(res, src + l, r - l);
    res[r - l] = 0;
    return res;
}

string _str_clone(string* src) {
    string str;
    str.len = src->len;
    memcpy(str.cstr, src->cstr, str.len);
    return str;
}
int8_t _str_is_alpha(string* str) {
    for (uint64_t i = 0; i < str->len-1; ++i) {
        if (*(str->cstr + i) < 0x41 || *(str->cstr + i) > 0x7A) {
            return 0;
        }
    }
    return 1;
}

int8_t _str_is_numeric(string* str) {
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

void _str_free(string* str) {
    free(str->cstr);
}

uint64_t _str_size_cstr(const char* str) {
    uint64_t i = 0;
    while (str[i++] != 0) { }
    return i;
}

int8_t _str_string_eql_string(string* s1, string* s2) {
    if (s1->len != s2->len) return 0;
    return _str_cstr_eql_cstr(s1->cstr, s2->cstr);
}

int8_t _str_string_eql_cstr(string* s1, const char* s2) {
    return _str_cstr_eql_cstr(s1->cstr, s2);
}

int8_t _str_cstr_eql_cstr(const char* s1, const char* s2) {
    for (uint64_t i = 0; ;++i) {
        if (s1[i] != s2[i]) return 0;
        if (s1[i] == 0 || s2[i] == 0) break;
    }
    return 1;
}
