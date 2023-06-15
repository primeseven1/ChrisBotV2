#pragma once

#include <bot/pch.h>

void slash_command_event_handler(const dpp::slashcommand_t& event);
void guild_member_add_event_handler(const dpp::guild_member_add_t& event);