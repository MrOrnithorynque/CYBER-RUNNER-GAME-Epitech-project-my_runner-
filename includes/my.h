/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Ashwin's my.h
*/

//----------------------------------DEFINES------------------------------------

#define error       84
#define BUFF_SIZE   4096
#define BG_1        "ressources/assets/parallax1.png"
#define BG_2        "ressources/assets/parallax2.png"
#define BG_3        "ressources/assets/parallax3.png"
#define BG_4        "ressources/assets/parallax4.png"
#define G_1         "ressources/assets/ground_1.png"
#define TRAIN       "ressources/assets/train.png"
#define RAIN        "ressources/assets/rain.png"
#define GIRL        "ressources/assets/girl_bike_all_sprites.png"
#define CAR         "ressources/assets/ae86.png"
#define MENU        "ressources/assets/menu.png"
#define PAUSE       "ressources/assets/pause.png"
#define DEATH_MENU  "ressources/assets/dead_screen.png"
#define MENU_THEME  "ressources/musics/VirtuaVerse.ogg"
#define MAIN_THEME  "ressources/musics/Dangerous_Corp.ogg"
#define MAIN_THEME2 "ressources/musics/Motördrone.ogg"
#define DEATH_THEME "ressources/musics/Mag_Police.ogg"
#define WIN_THEME   "ressources/musics/Cracktro.ogg"
#define RAIN_SOUND  "ressources/sound_effects/rain_sound_effect.ogg"
#define MOTOR_BIKE  "ressources/sound_effects/motorbike_sound_effect.ogg"
#define FIRE        "ressources/sound_effects/fire_pistol.wav"

//---------------------------------INCLUDES------------------------------------

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//-----------------------------------MACROS------------------------------------

#define CTOI(x) (x - 48)
#define ITOC(x) (x + 48)

//----------------------------------STRUCTS------------------------------------

typedef struct object_t
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    float speed;
    int status;
    struct object_t *next;
} object_s;

typedef struct music_t
{
    sfMusic *menu_theme;
    sfMusic *main_theme;
    sfMusic *main_theme2;
    sfMusic *death_theme;
    sfMusic *win_theme;
    sfMusic *rain_sound;
    sfMusic *motor_bike;
} music_s;

typedef struct sprites_t {
    sfSprite *train;
    sfSprite *end_menu;
    sfSprite *menu;
    sfSprite *pause;
    sfSprite *bg_4;
    sfSprite *rain_1;
    sfSprite *rain_2;
    sfVector2f pos_rain_1;
    sfVector2f pos_rain_2;
}sprites_s;

typedef struct window_t {
    struct sprites_t *sprite;
    struct object_t *object;
    struct object_t **parallax;
    struct object_t **ennemies;
    struct music_t *music;
    struct object_t *player;
    struct object_t *menu;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfClock *game_speed_clock;
    sfClock *player_clock;
    sfClock *ennemies_clock;
    sfClock *movement_clock;
    sfClock *score_clock;
    sfTime time;
    float speed;
    int nb_ennemies;
    int menu_f;
    int end_f;
    int pause;
}window_s;

//------------------------------------LIB--------------------------------------

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);

//------------------------------------SRC--------------------------------------

sfVector2f add_vect(float i, float j);
void analyse_events(window_s *game);
void animate_player(window_s *game, object_s *player);
void animate_player_next(window_s *game, object_s *player);
object_s **create_ennemie(sfVector2f pos, sfVector2f scale, int nb);
void create_music(window_s *game);
object_s *create_object(sfVector2f pos, sfVector2f scale, char *file_path);
object_s **create_parallax(sfVector2f pos_1, sfVector2f pos_2,\
sfVector2f scale);
object_s *create_player(sfVector2f pos, sfVector2f scale);
static sfRenderWindow *create_RenderWindow(unsigned int x, unsigned
int y, unsigned int bpp, char *title);
void display(window_s *game);
void end(window_s *game);
void endless_rain(window_s *game);
void end_menu(window_s *game);
sfSprite *get_sprite(char *file_path, sfVector2f scale);
void help(char **argv);
void help_menu(void);
void infin_parallax(window_s *game);
void initialisation(window_s *game);
void initialisation_pos(window_s *game);
void initialisation_music(window_s *game);
void initialisation_struct(window_s *game);
void manage_collision(window_s *game);
void manage_rendering(window_s *game);
void manage_scrolling(void);
void menu(window_s *game);
void mouse(sfRenderWindow *window, sfEvent event, sfSprite *sprite);
void move_ennemie(window_s *game);
void move_game(window_s *game);
void move_parallax(window_s *game, int speed);
int jump(window_s *game, object_s *player, int x);
void music_in_game(window_s *game);
void parallax(window_s *game);
void pause_game(window_s *game);
void player(window_s *game);
void player_input(window_s *game, object_s *player);
int random_number(int min, int max);
void resized(sfRenderWindow *window, sfEvent event);
void wich_audio(int music);