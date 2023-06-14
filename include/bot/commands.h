#pragma once

#include <bot/pch.h>

void slash_command_event_handler(const dpp::slashcommand_t& event);
void register_slash_commands(dpp::cluster& bot);

int ping_command(const dpp::slashcommand_t event);