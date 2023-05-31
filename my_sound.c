/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_sound.c
*/
#include "my_game.h"

int shot(GLOBAL_T *ALL)
{
    if (!ALL->music)
        return 84;
    sfMusic_play(ALL->music);
}
