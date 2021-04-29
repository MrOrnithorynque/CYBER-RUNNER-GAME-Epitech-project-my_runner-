/*
** EPITECH PROJECT, 2021
** manage
** File description:
** Functions that manage things.
*/

#include "../../includes/my.h"

void manage_rendering(window_s *game)
{
    initialisation_pos(game);
    parallax(game);
    infin_parallax(game);
    endless_rain(game);
    animate_player(game, game->player);
    if (game->menu_f <= 1)
        menu(game);
    else if (game->end_f > 1) {
        end_menu(game);
        move_ennemie(game);
    }
    else if (game->pause % 2 != 0)
        pause_game(game);
    else {
        initialisation_music(game);
        sfMusic_stop(game->music->menu_theme);
        move_ennemie(game);
        manage_collision(game);
    }
}

void manage_collision(window_s *game)
{
    for (int i = 0; i < game->nb_ennemies; i++) {
        if (game->ennemies[i]->pos.x < game->player->pos.x + 180 &&\
            game->ennemies[i]->pos.x + 200 > game->player->pos.x &&\
            game->ennemies[i]->pos.y == 530 && game->player->pos.y == 480)
            game->end_f += 1;
        if (game->ennemies[i]->pos.x < game->player->pos.x + 180 &&\
            game->ennemies[i]->pos.x + 200 > game->player->pos.x &&\
            game->ennemies[i]->pos.y == 600 && game->player->pos.y == 560)
            game->end_f += 1;
    }
}

void endless_rain(window_s *game)
{
    if (game->sprite->pos_rain_1.y >= 1080)
        sfSprite_setPosition(game->sprite->rain_1, add_vect(0, -1440.688));
    if (game->sprite->pos_rain_2.y >= 1080)
        sfSprite_setPosition(game->sprite->rain_2, add_vect(0, -1440.688));
}