/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** My_runner project.
*/

#include "../includes/my.h"

static sfRenderWindow * create_RenderWindow(unsigned int x, unsigned
int y, unsigned int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};
    sfUint32 style = sfResize | sfNone | sfTitlebar | sfClose;
    return (sfRenderWindow_create(mode, title, style, NULL));
}

void analyse_events(window_s *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    else if (game->event.type == sfEvtKeyPressed) {
        game->menu_f += 1;
        if (game->end_f > 1)
            end(game);
    }
}

void help_menu(void)
{
    my_putstr("\n\n+------------------------------------------------------+");
    my_putchar('\n');
    my_putstr("|  _____     __             ___                        |\n");
    my_putstr("| / ___/_ __/ /  ___ ____  / _ \\__ _____  ___  ___ ____|\n");
    my_putstr("|/ /__/ // / _ \\/ -_) __/ / , _/ // / _ \\/ _ \\/ -_) __/|\n");
    my_putstr("|\\___/\\_, /_.__/\\__/_/   /_/|_|\\_,_/_//_/_//_/\\__/_/");
    my_putstr("   |\n");
    my_putstr("|    /___/                                             |\n");
    my_putstr("| Epitech project 'my_runner' by louis Obéniche Rousse |\n");
    my_putstr("|                                                      |\n");
    my_putstr("| Goal of the game:                                    |\n");
    my_putstr("| You are on the freeway to go see your girl, dodge the|\n");
    my_putstr("| cars.                                                |\n");
    my_putstr("|                                                      |\n");
    my_putstr("| Controls:                                            |\n");
    my_putstr("| Up / Down : Z key / S key           All the sprites  |\n");
    my_putstr("| Left / Right : Q key / D key        are an orginal   |\n");
    my_putstr("| Jump:  Space bar Key                creation except  |\n");
    my_putstr("| Pause / Play: Escape Key / any Key  the train.       |\n");
    my_putstr("+------------------------------------------------------+\n\n");
}

int main(int argc, char **argv)
{
    window_s *game = malloc(sizeof(window_s));

    initialisation_struct(game);
    initialisation(game);
    if (argc == 2)
        help(argv);
    game->window = create_RenderWindow(1280, 720, 32, "Cyber Runner");
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(game->window, sfTrue);
    music_in_game(game);
    display(game);
    return 0;
}