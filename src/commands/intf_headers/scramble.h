#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <types.h>

void gen_moves(char* scramble_array, size_t scramble_length);
void gen_modifiers(char* modifiers_array, size_t modifiers_array_length);

#ifdef __cplusplus
}
#endif