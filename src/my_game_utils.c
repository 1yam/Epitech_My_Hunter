/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_gam_utils.c
*/
#include "my_game.h"
#include "my_macro_abs.h"
int my_putchar(char c);

sfIntRect get_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

int get_distance(sfVector2f coords_1, sfVector2f coords_2)
{
    int x = coords_1.x - coords_2.x;
    int y = coords_1.y - coords_2.y;
    if (ABS(x) <= 50 && ABS(y) <= 50)
        return 1;
    else
        return 0;
}

int get_distance_2(sfVector2f coords_1, sfVector2f coords_2)
{
    int x = coords_1.x - coords_2.x;
    int y = coords_1.y - coords_2.y;
    if (ABS(x) <= 25 && ABS(y) <= 25)
        return 1;
    else
        return 0;
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        my_putchar(*(str + i));
    };
    return 0;
}

int my_game_h(void)
{
    my_putstr("Usage : ./my_hunter \n");
    my_putstr("    STA : Shoot the AER is a duck hunt like game \n");
    my_putstr("    Here, u need to kill the AER of Epitech Lyon");
}
