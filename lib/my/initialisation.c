/*
** EPITECH PROJECT, 2021
** initialisation
** File description:
** Initialise things.
*/

#include "../../includes/my.h"

void initialisation(window_s *game)
{
    game->sprite->train = get_sprite(TRAIN, add_vect(1.6, 1.6));
    game->sprite->pause = get_sprite(PAUSE, add_vect(1.418, 1.418));
    game->sprite->end_menu = get_sprite(DEATH_MENU, add_vect(1.418, 1.418));
    game->sprite->menu = get_sprite(MENU, add_vect(1.418, 1.418));
    game->sprite->bg_4 = get_sprite(BG_4, add_vect(1.418, 1.418));
    game->sprite->rain_1 = get_sprite(RAIN, add_vect(1.418, 1.418));
    game->sprite->rain_2 = get_sprite(RAIN, add_vect(1.418, 1.418));
    sfSprite_setPosition(game->player->sprite, add_vect(-20, 480));
    sfSprite_setPosition(game->sprite->rain_2, add_vect(0, -1440.688));
    sfSprite_setPosition(game->sprite->train, add_vect(-3000, 400));
}

void initialisation_pos(window_s *game)
{
    for (int i = 0; i < 8; i++) {
        game->parallax[i]->pos =\
        sfSprite_getPosition(game->parallax[i]->sprite);
    }
    for (int i = 0; i < game->nb_ennemies; i++) {
        game->ennemies[i]->pos =\
        sfSprite_getPosition(game->ennemies[i]->sprite);
    }
    game->player->pos = sfSprite_getPosition(game->player->sprite);
    game->sprite->pos_rain_1 = sfSprite_getPosition(game->sprite->rain_1);
    game->sprite->pos_rain_2 =sfSprite_getPosition(game->sprite->rain_2);
}

void initialisation_struct(window_s *game)
{
    game->nb_ennemies = 3;
    game->sprite = malloc(sizeof(sprites_s));
    game->object = malloc(sizeof(object_s));
    game->music = malloc(sizeof(music_s));
    game->clock = sfClock_create();
    game->game_speed_clock = sfClock_create();
    game->player_clock = sfClock_create();
    game->movement_clock = sfClock_create();
    game->ennemies_clock = sfClock_create();
    game->score_clock = sfClock_create();
    game->parallax = create_parallax(add_vect(0, 0),add_vect(2129.836, 0),\
                                    add_vect(1.418, 1.418));
    game->ennemies = create_ennemie(add_vect(1000, 530), add_vect(2.7, 2.7),\
                                    game->nb_ennemies);
    game->player = create_player(add_vect(0, 480), add_vect(1.418, 1.418));
    create_music(game);
    game->player->status = 0;
    game->menu_f = 0;
    game->end_f = 0;
    game->pause = 0;
}