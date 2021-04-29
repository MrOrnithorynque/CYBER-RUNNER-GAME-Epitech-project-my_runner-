/*
** EPITECH PROJECT, 2021
** create
** File description:
** Functions that create sprites.
*/

#include "../../includes/my.h"

object_s *create_object(sfVector2f pos, sfVector2f scale, char *file_path)
{
    object_s *obj = malloc(sizeof(object_s));
    obj->sprite = sfSprite_create();
    obj->pos = pos;

    sfSprite_setTexture(obj->sprite,\
        sfTexture_createFromFile(file_path, NULL),\
        sfTrue);
    sfSprite_setScale(obj->sprite, scale);
    sfSprite_setPosition(obj->sprite, pos);

    return obj;
}

object_s **create_parallax(sfVector2f pos_1, sfVector2f pos_2,\
                            sfVector2f scale)
{
    object_s **parallax = malloc(sizeof(object_s *) * 8);
    char *file_path[] =\
        {BG_1, BG_1, BG_2, BG_2, BG_3, BG_3, G_1, G_1, NULL};

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0)
            parallax[i] = create_object(pos_1, scale, file_path[i]);
        else
            parallax[i] = create_object(pos_2, scale, file_path[i]);
    }
    for (int i = 0; i < 8; i++)
        sfSprite_setPosition(parallax[i]->sprite, parallax[i]->pos);

    return parallax;
}

object_s **create_ennemie(sfVector2f pos, sfVector2f scale, int nb)
{
    object_s **ennemie = malloc(sizeof(object_s *) * nb);
    int random[nb];
    int l = 300;

    for (int i = 0; i < nb; i++) {
        ennemie[i] = create_object(pos, scale, CAR);
        ennemie[i]->speed = -10;
    }
    for (int i = 0; i < nb; i++) {
        sfSprite_setPosition(ennemie[i]->sprite,\
                            add_vect(random_number(1300, 2500) + l, pos.y));
        l += 300;
    }

    return ennemie;
}

object_s *create_player(sfVector2f pos, sfVector2f scale)
{
    object_s *player = malloc(sizeof(object_s));
    sfIntRect rect_b = {0, 0, 180, 180};
    player->rect = rect_b;
    player->sprite = sfSprite_create();
    player->pos = pos;

    sfSprite_setTexture(player->sprite,\
        sfTexture_createFromFile(GIRL, NULL),\
        sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setScale(player->sprite, scale);
    sfSprite_setPosition(player->sprite, pos);

    return player;
}