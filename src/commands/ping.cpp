#include <bot/commands.h>

int ping_command(const dpp::slashcommand_t event)
{
    event.reply("Pong!");
    return 0;
}