/*
** EPITECH PROJECT, 2021
** useful
** File description:
** Useful functions for my_runner.
*/

#include "../../includes/my.h"

sfVector2f add_vect(float i, float j)
{
    sfVector2f vect = {i, j};

    return vect;
}

sfSprite *get_sprite(char *file_path, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite,\
        sfTexture_createFromFile(file_path, NULL),\
        sfTrue);
    sfSprite_setScale(sprite, scale);

    return sprite;
}

int random_number(int min, int max)
{
    int res = (rand() % (max - min + 1)) + min;

    return res;
}

void create_music(window_s *game)
{
    game->music->menu_theme = sfMusic_createFromFile(MENU_THEME);
    game->music->main_theme = sfMusic_createFromFile(MAIN_THEME);
    game->music->main_theme2 = sfMusic_createFromFile(MAIN_THEME2);
    game->music->death_theme = sfMusic_createFromFile(DEATH_THEME);
    game->music->win_theme = sfMusic_createFromFile(WIN_THEME);
    game->music->rain_sound = sfMusic_createFromFile(RAIN_SOUND);
    game->music->motor_bike = sfMusic_createFromFile(MOTOR_BIKE);
}

void help(char **argv)
{
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        help_menu();
}