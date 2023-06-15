#include <bot/pch.h>
#include <bot/commands.h>
#include <private/bot_info.h>

static void handle_command_line_args(int argc, char** argv, dpp::cluster& bot)
{
    if (argc > 1)
    {
        if (argc > 2)
            std::cout << "More than 1 command line argument, the args after the first one are ignored\n";

        std::string argument = static_cast<std::string>(argv[1]);

        if (argument == "register-slash-commands")
        {
            register_slash_commands(bot);
            return;
        }

        std::cout << "Unknown argument: " << argv[1] << "\nValid arguments: register-slash-commands\n";
        exit(1);
    }
}

int main(int argc, char** argv)
{
    dpp::cluster bot(TOKEN);

    bot.on_log(dpp::utility::cout_logger());
    bot.on_ready([&bot, argc, argv](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>())
            handle_command_line_args(argc, argv, bot);

        std::cout << "Ready!" << std::endl;
    });
    bot.on_slashcommand(slash_command_event_handler);

    srand(time(0));

    bot.start(dpp::st_wait);
    return 0;
}