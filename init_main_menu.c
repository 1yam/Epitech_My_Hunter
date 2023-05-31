/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** init_main_menu.c
*/
#include "my_game.h"

int init_main_menu(GLOBAL_T *ALL)
{
    int n = 0;
    ALL->m.texture = sfTexture_createFromFile("./data/MainMenu.png", NULL);
    ALL->m.sprite = sfSprite_create();
    ALL->m.scale.x = 1;
    ALL->m.scale.y = 1;
    ALL->m.pos.x = 0;
    ALL->m.pos.y = 0;
    ALL->m.state = sfTrue;
    sfVector2f scale = ALL->m.scale;
    sfSprite_setScale(ALL->m.sprite, ALL->m.scale);
}

char *int_to_char(int nbr)
{
    int len = number_digits(nbr);
    if (!len)
        return "0";
    char *result;

    result = malloc(sizeof(char) * len);
    if (!result)
        return "0";

    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return result;
}

int number_digits(int nbr)
{
    int n = 1;
    int p = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= p) {
        n++;
        if (p > 214748364)
            break;
        p *= 10;
    }
    return (n);
}

int init_var(GLOBAL_T *ALL)
{
    ALL->score = 0;
    ALL->hp = 84;
    ALL->speed = 0.5;
    ALL->rotations = 0;
    ALL->nbr_img = 2;
    ALL->nbr_ammo = 5;
    ALL->game_launched = sfFalse;
    ALL->music = sfMusic_createFromFile("./data/sound/shotgun.wav");
    ALL->font = sfFont_createFromFile("./data/font/my_font.ttf");
}
