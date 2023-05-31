/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_cursor.c
*/
#include "my_game.h"

int init_cursor(GLOBAL_T *ALL)
{
    cur.texture = sfTexture_createFromFile("./data/cros.png", NULL);
    cur.sprite = sfSprite_create();
    sfSprite_setScale(cur.sprite, (sfVector2f){0.3, 0.3});
}

int update_crosshair(GLOBAL_T *ALL)
{
    sfSprite_setTexture(cur.sprite, cur.texture, sfTrue);
    sfVector2f f_cursor;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(WINDOW);
    sfWindow_setMouseCursorVisible(WINDOW, sfFalse);
    f_cursor = sfRenderWindow_mapPixelToCoords(WINDOW, mouse_pos, NULL);
    f_cursor.x = f_cursor.x - 48;
    f_cursor.y = f_cursor.y - 30;
    sfSprite_setPosition(cur.sprite, f_cursor);
    sfRenderWindow_drawSprite(WINDOW, cur.sprite, NULL);
}
