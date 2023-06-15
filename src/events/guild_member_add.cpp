#include <bot/pch.h>

void guild_member_add_event_handler(const dpp::guild_member_add_t& event)
{
    // Probably going to want to do something else, like log it to a channel or something rather than cout
    std::cout << "Member added to server: " << event.added.user_id << "\n" << "Server ID: " << event.added.guild_id;
}