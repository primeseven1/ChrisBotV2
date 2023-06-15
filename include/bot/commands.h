#pragma once

#include <bot/pch.h>

void slash_command_event_handler(const dpp::slashcommand_t& event);
void register_slash_commands(dpp::cluster& bot);

int ping_command(const dpp::slashcommand_t& event);
int scramble_command(const dpp::slashcommand_t& event);
int coin_flip(const dpp::slashcommand_t& event);