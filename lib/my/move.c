/*
** EPITECH PROJECT, 2021
** move
** File description:
** Move sprites.
*/

#include "../../includes/my.h"

void move_parallax(window_s *game, int speed)
{
    sfSprite_move(game->parallax[4]->sprite, add_vect(-0.1 + speed, 0));
    sfSprite_move(game->parallax[5]->sprite, add_vect(-0.1 + speed, 0));
    sfSprite_move(game->parallax[2]->sprite, add_vect(-0.5 + speed, 0));
    sfSprite_move(game->parallax[3]->sprite, add_vect(-0.5 + speed, 0));
    sfSprite_move(game->parallax[0]->sprite, add_vect(-2 + speed, 0));
    sfSprite_move(game->parallax[1]->sprite, add_vect(-2 + speed, 0));
    sfSprite_move(game->parallax[6]->sprite, add_vect(-7 + speed, 0));
    sfSprite_move(game->parallax[7]->sprite, add_vect(-7 + speed, 0));
    sfSprite_move(game->sprite->train, add_vect(4 + speed, 0));
    sfSprite_move(game->sprite->rain_1, add_vect(-10, 10));
    sfSprite_move(game->sprite->rain_2, add_vect(-10, 10));
}

int jump(window_s *game, object_s *player, int x)
{
    int position[5] = {-50, -50, -10, 50, 60};

    sfSprite_move(player->sprite, add_vect(50, position[x]));
    x++;
    return x;
}

void move_ennemie(window_s *game)
{
    int l = random_number(0, 1);

    for (int i = 0; i < game->nb_ennemies; i++) {
        if (l == 0) {
            if (game->ennemies[i]->pos.x < -500)
                sfSprite_setPosition(game->ennemies[i]->sprite,\
                                    add_vect(random_number(1280, 2600), 530));
        } else if (game->ennemies[i]->pos.x < -500)
                sfSprite_setPosition(game->ennemies[i]->sprite,\
                                    add_vect(random_number(1600, 2900), 600));
    }
    for (int i = 0; i < game->nb_ennemies; i++) {
        sfSprite_move(game->ennemies[i]->sprite,\
                    add_vect(-10 + game->speed, 0));
    }
}

void move_game(window_s *game)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 0.02) {
            move_parallax(game, game->speed);
            sfClock_restart(game->clock);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(\
                        game->game_speed_clock)) > 0.01) {
        game->speed = game->speed - 0.0003;
        sfClock_restart(game->game_speed_clock);
    }
}