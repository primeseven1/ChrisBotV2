#include <bot/pch.h>
#include <bot/commands.h>

void slash_command_event_handler(const dpp::slashcommand_t& event)
{
    static std::unordered_map<std::string, std::function<int(const dpp::slashcommand_t&)>> command_map = {
        { "ping", ping_command }
    };

    std::string command_name = event.command.get_command_name();
    std::string command_error_message;

    if (command_map.count(command_name))
    {
        int return_value;

        if ((return_value = command_map[command_name](event)) != 0)
        {
            command_error_message = "Command failed to execute (" + command_name + "): Returned " + std::to_string(return_value);
            event.reply(command_error_message);
        }
        
        return;
    }
    
    std::cout << "Warning:\nInvalid command used: " << command_name << std::endl;
    command_error_message = "Invalid command (" + command_name + "): Not implimented";
    event.reply(command_error_message);
}