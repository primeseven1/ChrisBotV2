#include <stdlib.h>
#include <stdbool.h>
#include "../../intf_headers/scramble.h"
#include "./valid.h"

void gen_moves(char* scramble_array, uint8_t scramble_length)
{
    if (!scramble_array)
        return;

    static const char moves[] = "UDRLFB";

    for (uint8_t i = 0; i < scramble_length; i++)
    {
        scramble_array[i] = moves[rand() % (sizeof(moves) - 1)];
        if (!valid(scramble_array, i))
            i--;
    }
}

void gen_modifiers(char* modifiers_array, uint8_t modifiers_array_length)
{
    if (!modifiers_array)
        return;

    static const char modifiers[] = "'2 ";

    for (uint8_t i = 0; i < modifiers_array_length; i++)
        modifiers_array[i] = modifiers[rand() % (sizeof(modifiers) - 1)];
}