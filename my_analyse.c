/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_analyse.c
*/
#include "my_game.h"
void manage_mouse_click(sfMouseButtonEvent event, GLOBAL_T *ALL)
{
    shot(ALL);
    int touch = 0; int can_touch = -1;
    for (int i = 2; i <= 1 + ALL->bird_nbr; i++) {
        sfVector2f f_cursor;
        sfVector2f my_sprite;
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);
        f_cursor = sfRenderWindow_mapPixelToCoords(WINDOW, mouse_pos, NULL);
        my_sprite = ALL->b[i].pos;
        int my_distance = get_distance(f_cursor, my_sprite);
        if (my_distance == 1 && can_touch == -1){
            can_touch = i;
            ALL->b[i].pos.x = -10;
            ALL->b[i].pos.y = float_rand(100, 500);
            ALL->score = ALL->score + 500;
            ALL->b[i].speed = ALL->b[i].speed * 0.8;
            ALL->b[i].move_pixel = sa.move_pixel + (sa.move_pixel * 0.8);
            ALL->speed = ALL->speed * 0.98;
        }
    }
    (can_touch == -1) ? (ALL->nbr_ammo = ALL->nbr_ammo - 1) : 0;
}

void manage_main(sfMouseButtonEvent event, GLOBAL_T *ALL)
{
    ALL->hp = 84;

    sfVector2f test;
    test.x = event.x;
    test.y = event.y;
    sfVector2u test2 = sfWindow_getSize(WINDOW);
    sfVector2f parse_f;
    parse_f.x = (float) test2.x / 2;
    parse_f.y = (float) test2.y / 2;
    if (get_distance(test, parse_f) == 1)
        ALL->game_launched = sfTrue;
}

void close_window(sfRenderWindow *window, GLOBAL_T *ALL)
{
    ALL->game_launched = sfFalse;
    sfRenderWindow_close(ALL->settings.window);
}

void analyse_events(sfRenderWindow *window, sfEvent event, GLOBAL_T *ALL)
{
    (event.type == sfEvtResized) ? (
        ALL->music = sfMusic_createFromFile("./data/sound/shotgun.wav")
    ) : 0;
    (event.type == sfEvtKeyPressed) ? (sound(ALL)) : 0;
    (event.type == sfEvtClosed) ? (close_window(window, ALL)) : 0;
    (event.type == sfEvtMouseButtonPressed && ALL->game_launched) ?
    (manage_mouse_click(event.mouseButton, ALL)) : 0;
    (event.type == sfEvtMouseButtonPressed && !ALL->game_launched) ?
    (manage_main(event.mouseButton, ALL)) : 0;
}
