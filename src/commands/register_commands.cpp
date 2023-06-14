#include <bot/commands.h>

void register_slash_commands(dpp::cluster& bot)
{
    bot.global_command_create(dpp::slashcommand("ping", "Replies with pong", bot.me.id));
    std::cout << "Successfully registered slash commands\n";
}