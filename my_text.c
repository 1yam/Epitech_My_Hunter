/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_text.c
*/
#include "my_game.h"

void init_text(GLOBAL_T *ALL)
{
    ALL->ammo = sfText_create();
    ALL->bird_nbr = 0;
    char ammu = (ALL->nbr_ammo + '0');
    char s_ammo[2];
    s_ammo[0] = ammu;
    s_ammo[1] = '\0';

    sfText_setString(ALL->ammo, s_ammo);
    sfText_setFont(ALL->ammo, ALL->font);
    sfText_setCharacterSize(ALL->ammo, 50);
    ALL->t_ammo = sfText_create();
    ALL->t_hp = sfText_create();
    ALL->t_score = sfText_create();
}

void update_text(GLOBAL_T *ALL)
{
    sfText_setString(ALL->t_hp, int_to_char(ALL->hp));
    sfText_setString(ALL->t_ammo, int_to_char(ALL->nbr_ammo));
    sfVector2f hp_pos = (sfVector2f) {100, 525};
    sfVector2f ammo_pos = (sfVector2f) {225, 525};
    sfText_setPosition(ALL->t_hp, hp_pos);
    sfText_setPosition(ALL->t_ammo, ammo_pos);
    sfText_setFont(ALL->t_hp, ALL->font);
    sfText_setFont(ALL->t_ammo, ALL->font);
    sfText_setCharacterSize(ALL->t_hp, 50);
    sfText_setCharacterSize(ALL->t_ammo, 50);
    sfRenderWindow_drawText(ALL->settings.window, ALL->t_hp, NULL);
    sfRenderWindow_drawText(ALL->settings.window, ALL->t_ammo, NULL);
}
