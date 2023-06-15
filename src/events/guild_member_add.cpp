#include <bot/pch.h>

void guild_member_add_event_handler(const dpp::guild_member_add_t& event)
{
    std::cout << "guild_member_add_event_handler triggered" << std::endl;
}