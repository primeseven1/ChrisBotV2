#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

void gen_moves(char* scramble_array, uint8_t scramble_length);
void gen_modifiers(char* modifiers_array, uint8_t modifiers_array_length);

#ifdef __cplusplus
}
#endif