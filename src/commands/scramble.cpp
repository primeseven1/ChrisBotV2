#include <bot/pch.h>
#include <bot/commands.h>
#include "./intf_headers/scramble.h"

int scramble_command(const dpp::slashcommand_t& event)
{
    char scramble_array[28];
    gen_moves(scramble_array, sizeof(scramble_array) - 1);
    scramble_array[27] = '\0';

    char scramble_modifiers_array[28];
    gen_modifiers(scramble_modifiers_array, sizeof(scramble_modifiers_array) - 1);
    scramble_modifiers_array[27] = '\0';

    std::string scramble = static_cast<std::string>(scramble_array);
    std::string modifers = static_cast<std::string>(scramble_modifiers_array);
    std::string full_scramble;

    for (size_t i = 0; i < sizeof(scramble_array) - 1; i++)
    {
        full_scramble += scramble[i];
        full_scramble += modifers[i];

        if (modifers[i] != ' ')
            full_scramble += ' ';
    }

    event.reply(full_scramble);

    return 0;
}