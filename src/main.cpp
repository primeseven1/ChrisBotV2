#include <bot/pch.h>
#include <bot/commands.h>
#include <private/bot_info.h>

int main()
{
    dpp::cluster bot(TOKEN);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>())
            std::cout << "Ready!" << std::endl;
    });
    bot.on_slashcommand(slash_command_event_handler);

    bot.start(dpp::st_wait);
    return 0;
}