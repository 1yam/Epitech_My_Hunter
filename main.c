/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** main.c
*/

#include "my_game.h"
int anim_bird(GLOBAL_T *ALL);

static void play (GLOBAL_T *ALL)
{
    sfClock* anim; sfClock* clock;
    clock = sfClock_create(); anim = sfClock_create();
    while (sfRenderWindow_isOpen(WINDOW)) {
        sfBool foc = sfRenderWindow_hasFocus(WINDOW);
        while (sfRenderWindow_pollEvent(WINDOW, &EVENT))
            analyse_events(WINDOW, EVENT, ALL);
        (ALL->game_launched && foc) ? (game(ALL)) : 0;
        (!ALL->game_launched && foc) ? (main_menu(ALL)) : 0;
    }
    destroy_game(ALL);
}

int game(GLOBAL_T *ALL)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    game_update(ALL);
    anim_bird(ALL);
    move_bird(ALL);
    for (int i = 0; i <= 1 + ALL->bird_nbr; i++){
        sfSprite_setTexture(ALL->b[i].sprite, ALL->b[i].texture, sfTrue);
        if (i > 1)
            sfSprite_setTextureRect(ALL->b[i].sprite, ALL->b[i].rect);
        sfRenderWindow_drawSprite(WINDOW, ALL->b[i].sprite, NULL);
    }
    update_text(ALL);
    update_crosshair(ALL);
    sfRenderWindow_drawText(WINDOW, ALL->ammo, NULL);
    sfRenderWindow_display(WINDOW);
}

int main_menu(GLOBAL_T *ALL)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfWindow_setMouseCursorVisible(WINDOW, sfTrue);
    sfSprite_setTexture(ALL->m.sprite, ALL->m.texture, sfTrue);
    sfRenderWindow_drawSprite(WINDOW, ALL->m.sprite, NULL);
    sfText_setString(ALL->ammo, int_to_char(ALL->best_score));
    sfVector2f test = (sfVector2f) {0, sfWindow_getSize(WINDOW).y / 2};
    sfText_setPosition(ALL->ammo, test);
    sfRenderWindow_drawText(WINDOW, ALL->ammo, NULL);
    sfRenderWindow_display(WINDOW);
}

int main (int argc, char** argv)
{
    if (argc == 1) {
        GLOBAL_T ALL;
        init(&ALL);
        play(&ALL);
        return 0;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_game_h();
        return 0;
    }
    return 84;
}

int destroy_game(GLOBAL_T *ALL)
{
    for (int i = 0; i <= 1 + ALL->bird_nbr; i++){
        sfClock_destroy(ALL->b[i].anim);
        sfClock_destroy(ALL->b[i].mov_time);
        sfTexture_destroy(ALL->b[i].texture);
        sfSprite_destroy(ALL->b[i].sprite);
    }
    sfText_destroy(ALL->ammo);sfFont_destroy(ALL->font);
    sfText_destroy(ALL->t_ammo);
    sfText_destroy(ALL->t_hp);
    sfText_destroy(ALL->t_score);
    sfMusic_destroy(ALL->music);
    sfRenderWindow_destroy(ALL->settings.window);
    sfTexture_destroy(ALL->m.texture);
    sfSprite_destroy(ALL->m.sprite);
}
