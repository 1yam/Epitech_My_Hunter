/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_game.c
*/
#include "my_game.h"
void init_bird(GLOBAL_T *ALL);

int move_bird(GLOBAL_T *ALL)
{
    for (int t = 2; t <= 1 + ALL->bird_nbr; t++) {
        time_t test;
        test = sfClock_getElapsedTime(ALL->b[t].mov_time).microseconds;
        float sec = test / 1000000.0;
        if (ALL->hp > 0 && sec > ALL->b[t].speed){
            (sec < 0.001) ? (init_bird(ALL), ALL->b[t].speed = ALL->speed ) : 0;
            sfClock_restart(ALL->b[t].mov_time);
            sfVector2f test = ALL->b[t].pos;
            (test.x > 800) ? (ALL->b[t].pos.x = 0, ALL->hp = ALL->hp - 21) : 0;
            ALL->b[t].pos.x = ALL->b[t].pos.x + ALL->b[t].move_pixel;
            sfSprite_setPosition(ALL->b[t].sprite, ALL->b[t].pos);
        }
    }
}

int anim_bird(GLOBAL_T *ALL)
{
    for (int t = 2; t <= 1 + ALL->bird_nbr; t++) {
        time_t time_anim;
        time_anim = sfClock_getElapsedTime(ALL->b[t].anim).microseconds;
        float sec = time_anim / 1000000.0;
        if (ALL->hp > 0 && sec > float_rand(0.08, 0.10)){
            sfIntRect anim;
            int change = 0;
            ALL->b[t].rect.height = 110;
            ALL->b[t].rect.width = 110;
            (ALL->b[t].rect.left < 330) ? (ALL->b[t].rect.left += 110) : 0;
            (ALL->b[t].rect.left == 330) ? (ALL->b[t].rect.left = 0) : 0;
            sfSprite_setTextureRect(ALL->b[t].sprite, ALL->b[t].rect);
            sfIntRect text_rect = sfSprite_getTextureRect(ALL->b[t].sprite);
            sfClock_restart(ALL->b[t].anim);
        }
    }
}

int game_update(GLOBAL_T *ALL)
{
    char ammu = (ALL->nbr_ammo + '0');
    char s_ammo[2];
    s_ammo[0] = ammu;
    s_ammo[1] = '\0';
    (ALL->hp <= 0) ? (
        ALL->best_score = ALL->score,
        reset_speed(ALL),
        init_text(ALL),
        init_var(ALL),
        ALL->game_launched = sfFalse,
        ALL->bird_nbr = ALL->bird_nbr + 1
    ) : 0;
    char* score = int_to_char(ALL->score);
    char *hp = int_to_char(ALL->hp);
    sfText_setString(ALL->ammo, score);
    sfText_setPosition(ALL->ammo, (sfVector2f) {0,0});
    if (ALL->nbr_ammo == 0) {
        ALL->nbr_ammo = 5;
        ALL->hp = ALL->hp - 21;
    }
}

int reset_speed(GLOBAL_T *ALL)
{
    for (int t = 2; t <= 1 + ALL->bird_nbr; t++) {
        sfClock_restart(ALL->b[t].anim);
        sfClock_restart(ALL->b[t].mov_time);
        ALL->b[t].speed = 0.5;
        ALL->b[t].pos.x = 0;
        ALL->b[t].move_pixel = 1;
    }
}
