#include <bot/commands.h>

int coin_flip(const dpp::slashcommand_t& event)
{
    std::string result = rand() % 2 == 1 ? "Heads" : "Tails";
    event.reply(result);
    return 0;
}