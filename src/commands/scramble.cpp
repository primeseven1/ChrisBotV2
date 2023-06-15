#include <bot/pch.h>
#include <bot/commands.h>
#include "./intf_headers/scramble.h"

int scramble_command(const dpp::slashcommand_t& event)
{
    char scramble_array[28];
    memset(scramble_array, 0, sizeof(scramble_array));
    gen_moves(scramble_array, sizeof(scramble_array) - 1);

    char scramble_modifiers_array[28];
    memset(scramble_modifiers_array, 0, sizeof(scramble_modifiers_array));
    gen_modifiers(scramble_modifiers_array, sizeof(scramble_modifiers_array) - 1);

    std::string scramble = static_cast<std::string>(scramble_array);
    std::string modifers = static_cast<std::string>(scramble_modifiers_array);
    std::string full_scramble;

    for (size_t i = 0; i < sizeof(scramble_array) - 1; i++)
    {
        full_scramble += scramble[i];
        full_scramble += modifers[i];

        // Prevents double spaces if the modifier is a space
        if (modifers[i] != ' ')
            full_scramble += ' ';
    }

    event.reply(full_scramble);

    return 0;
}