/*
** EPITECH PROJECT, 2021
** menu
** File description:
** Display menu and usage, if ask on the terminal.
*/

#include "../../includes/my.h"

void menu(window_s *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprite->menu, NULL);
    if (game->menu_f == 1) {
        sfSprite_destroy(game->sprite->menu);
        game->menu_f = 2;
        music_in_game(game);
    }
    game->speed = 0;
}

void end_menu(window_s *game)
{
    static int flag = 0;

    sfMusic_stop(game->music->main_theme);
    sfMusic_stop(game->music->motor_bike);
    if (flag == 0) {
        sfMusic_play(game->music->death_theme);
        game->player->sprite =\
            get_sprite("ressources/assets/death_girl.png", add_vect(1, 1));
    }
    flag++;
    sfRenderWindow_drawSprite(game->window, game->sprite->end_menu, NULL);
}

void end(window_s *game)
{
    sfRenderWindow_close(game->window);
}

void pause_game(window_s *game)
{
    sfMusic_setVolume(game->music->main_theme, 5);
    sfMusic_setVolume(game->music->main_theme2, 5);
    sfMusic_setVolume(game->music->motor_bike, 0);
    sfRenderWindow_drawSprite(game->window, game->sprite->pause, NULL);
}