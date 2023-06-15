#include <bot/pch.h>

void guild_delete_event_handler(const dpp::guild_delete_t& event)
{
    std::cout << "guild_delete_event_handler triggered" << std::endl;
}