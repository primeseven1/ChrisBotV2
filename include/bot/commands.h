#pragma once

#include <bot/pch.h>

void register_slash_commands(dpp::cluster& bot);

int ping_command(const dpp::slashcommand_t& event);
int scramble_command(const dpp::slashcommand_t& event);
int coinflip_command(const dpp::slashcommand_t& event);