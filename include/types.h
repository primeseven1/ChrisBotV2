#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef signed long ssize_t;

#ifndef __cplusplus

typedef _Bool bool;

#define true 1
#define false 0

#endif // __cplusplus