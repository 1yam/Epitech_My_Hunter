/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_secret_settings.c
*/
#include "my_game.h"

int sound(GLOBAL_T *ALL)
{
    ALL->music = sfMusic_createFromFile("./data/sound/Tire_v1.wav");
}
