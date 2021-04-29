/*
** EPITECH PROJECT, 2021
** audio
** File description:
** Functions about audio and musics of the game.
*/

#include "../../includes/my.h"

void music_in_game(window_s *game)
{
    if (game->menu_f < 2) {
        sfMusic_play(game->music->menu_theme);
        sfMusic_setLoop(game->music->menu_theme, sfTrue);
    } else
        sfMusic_play(game->music->main_theme);
    sfMusic_play(game->music->rain_sound);
    sfMusic_play(game->music->motor_bike);
    sfMusic_setLoop(game->music->main_theme, sfTrue);
    sfMusic_setLoop(game->music->death_theme, sfTrue);
    sfMusic_setLoop(game->music->rain_sound, sfTrue);
    sfMusic_setLoop(game->music->motor_bike, sfTrue);
}

void initialisation_music(window_s *game)
{
    sfMusic_setVolume(game->music->menu_theme, 30);
    sfMusic_setVolume(game->music->main_theme, 38);
    sfMusic_setVolume(game->music->main_theme2, 25);
    sfMusic_setVolume(game->music->death_theme, 20);
    sfMusic_setVolume(game->music->win_theme, 30);
    sfMusic_setVolume(game->music->rain_sound, 5);
    sfMusic_setVolume(game->music->motor_bike, 10);
}