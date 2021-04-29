/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** fonction importante
*/

#include "../../includes/my.h"

int my_put_nbr(int nb)
{
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}
