/*
** EPITECH PROJECT, 2021
** animation
** File description:
** Functions that animate differents sprites.
*/

#include "../../includes/my.h"

void animate_player(window_s *game, object_s *player)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->player_clock)) > 0.1) {
        if (player->status == 0) {
            if (player->rect.left == 0)
                player->rect.left = 180;
            else
                player->rect.left = 0;
            sfSprite_setTextureRect(player->sprite, player->rect);
        }
        if (player->status == 1) {
            if (player->rect.left == 360)
                player->rect.left = 540;
            else
                player->rect.left = 360;
            sfSprite_setTextureRect(player->sprite, player->rect);
            player->status = 0;
        }
        animate_player_next(game, player);
    }
}

void animate_player_next(window_s *game, object_s *player)
{
    static int x = 0;
    static int i = 0;

    if (player->status == 2) {
        if (player->rect.left != 1620) {
            player->rect.left += 180;
            x = jump(game, player, x);
        }
        else {
            player->status = 0;
            x = 0;
        }
        sfSprite_setTextureRect(player->sprite, player->rect);
    }
    if (i % 2 == 0)
        sfSprite_move(player->sprite, add_vect(0, -1));
    else
        sfSprite_move(player->sprite, add_vect(0, 1));
    i++;
    sfClock_restart(game->player_clock);
}