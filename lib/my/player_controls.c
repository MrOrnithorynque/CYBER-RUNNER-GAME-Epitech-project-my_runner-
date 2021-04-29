/*
** EPITECH PROJECT, 2021
** player_controls
** File description:
** Manage the inputs and the movements of the player.
*/

#include "../../includes/my.h"

void player_input(window_s *game, object_s *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) == sfTrue)
        sfSprite_setPosition(player->sprite, add_vect(player->pos.x, 480));
    if (sfKeyboard_isKeyPressed(sfKeyS) == sfTrue)
        sfSprite_setPosition(player->sprite, add_vect(player->pos.x, 560));
    if (sfKeyboard_isKeyPressed(sfKeyD) == sfTrue) {
        sfSprite_move(player->sprite, add_vect(15, 0));
        player->status = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) == sfTrue)
        sfSprite_move(player->sprite, add_vect(-10, 0));
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        player->rect.left = 720;
        sfSprite_setTextureRect(player->sprite, player->rect);
        player->status = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        game->pause += 1;
}