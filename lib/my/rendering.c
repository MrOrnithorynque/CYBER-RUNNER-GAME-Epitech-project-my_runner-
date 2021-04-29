/*
** EPITECH PROJECT, 2021
** rendering
** File description:
** Render things that needs to be rendered.
*/

#include "../../includes/my.h"

void display(window_s *game)
{
    game->speed = 0;

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            analyse_events(game);
        player_input(game, game->player);
        sfRenderWindow_clear(game->window, sfBlack);
        manage_rendering(game);
        move_game(game);
        sfRenderWindow_display(game->window);
    }
    sfRenderWindow_destroy(game->window);
}

void parallax(window_s *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprite->bg_4, NULL);
    for (int i = 5; i >= 0; i--)
        sfRenderWindow_drawSprite(game->window,\
                                game->parallax[i]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite->train, NULL);
    sfRenderWindow_drawSprite(game->window, game->parallax[7]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->parallax[6]->sprite, NULL);
    for (int i = 0; i < game->nb_ennemies; i++) {
        if (game->ennemies[i]->pos.y == 530)
            sfRenderWindow_drawSprite(game->window,\
                                    game->ennemies[i]->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    for (int i = 0; i < game->nb_ennemies; i++) {
        if (game->ennemies[i]->pos.y == 600)
            sfRenderWindow_drawSprite(game->window,\
                                    game->ennemies[i]->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->sprite->rain_1, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite->rain_2, NULL);
}

void infin_parallax(window_s *game)
{
    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            if (game->parallax[i]->pos.x < -2129.836) {
                sfSprite_setPosition(game->parallax[i]->sprite,\
            add_vect(game->parallax[i + 1]->pos.x + 2129.836, 0));
            }
        } else {
            if (game->parallax[i]->pos.x < -2129.836) {
                sfSprite_setPosition(game->parallax[i]->sprite,\
            add_vect(game->parallax[i - 1]->pos.x + 2129.836, 0));
            }
        }
    }
}