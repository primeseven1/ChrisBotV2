#include <bot/pch.h>

void guild_create_event_handler(const dpp::guild_create_t& event)
{
    std::cout << "guild_create_event_handler triggered" << std::endl;
}