/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** fonction importante
*/

int num(char const *str, int i)
{
    int b = 0;

    for (int i = 0; str[i] < '0' && str[i] > '9' || str[i] != '\0'; i++) {
        while (str[i] >= '0' && str[i] <= '9')
            return b;
        b++;
    }
    return 0;
}

int op(char const *str, long result)
{
    for (int a = 0; str[a] < '0' && str[a] > '9' || str[a] != '\0'; a++) {
        while (str[a] >= '0' && str[a] <= '9')
            return result;
        if (str[a] == '-')
            result = result * -1;
    }
    return result;
}

int my_getnbr(char const *str)
{
    long result = 0;
    int i = 0;
    int a = 0;

    i = num(str, i);
    while ((str[i] >= '0') && (str[i] <= '9')) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if ((result >= 2147483647) || (result <= -2147483648))
        return 121212121;
    result = op(str, result);
    return ((int)result);
}
