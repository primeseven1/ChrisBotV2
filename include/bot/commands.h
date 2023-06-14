#pragma once

#include <bot/pch.h>

void slash_command_event_handler(const dpp::slashcommand_t& event);

int ping_command(const dpp::slashcommand_t event);