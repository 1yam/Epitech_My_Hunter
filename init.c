/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** init.c
*/
#include "my_game.h"

float float_rand(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

void init_window(GLOBAL_T *ALL)
{
    modes.bitsPerPixel = 64;
    modes.height = 600;
    modes.width = 800;
    windows = sfRenderWindow_create(modes, "STA", sfResize | sfClose, NULL);
    text.path = malloc(sizeof(char*) * 250);
    text.path[0] = "./data/AER/Bluet.png";
    text.path[1] = "./data/AER/Green.png";
    text.path[2] = "./data/AER/Pink.png";
    text.path[3] = "./data/AER/Red.png";
    text.path[4] = "./data/AER/Yellow.png";
    text.path[5] = "./data/Pedago/adrien.png";
    text.path[6] = "./data/Pedago/adrien.png";
    text.path[7] = "";
}

void init_sprite(GLOBAL_T *ALL)
{
    ALL->b = malloc(sizeof(ALL->b) * 100);
    nb = 0;
    s.texture = sfTexture_createFromFile("./data/GameBackground.jpg", NULL);
    s.sprite = sfSprite_create();
    s.anim = sfClock_create(); s.mov_time = sfClock_create();
    s.scale.x = 1.25; s.scale.y = 1.25;
    s.pos.x = 0; s.pos.y = 0;
    s.state = sfTrue;
    sfVector2f scale = s.scale;
    sfSprite_setScale(s.sprite, s.scale);
    nb++;
    s.texture = sfTexture_createFromFile("./data/assistant.png", NULL);
    s.sprite = sfSprite_create();
    s.anim = sfClock_create(); s.mov_time = sfClock_create();
    s.scale.x = 0.25; s.scale.y = 0.25;
    s.pos.x = 30; s.pos.y = 530;
    s.state = sfTrue;
    sfSprite_setScale(s.sprite, s.scale);
    sfSprite_setPosition(s.sprite, s.pos);
}

void init_bird(GLOBAL_T *ALL)
{
    int t = ALL->bird_nbr + 2;
    (ALL->bird_nbr == 6) ? (ALL->bird_nbr = 0) : 0;
    if (ALL->bird_nbr <= 5) {
        nb = 2 + ALL->bird_nbr;
        s.texture = sfTexture_createFromFile(text.path[ALL->bird_nbr], NULL);
        s.sprite = sfSprite_create();
        s.scale.x = 0.5; s.scale.y = 0.5;
        s.pos.x = 0; s.pos.y = 400;
        s.state = sfTrue; s.move_pixel = 1;
        s.mov_time = sfClock_create(); s.anim = sfClock_create();
        s.speed = ALL->speed; ALL->touched = 0;
        sfVector2f scale = s.scale;
        ALL->b[nb].rect = get_rect(0, 0, 110, 110);
        sfSprite_setTextureRect(s.sprite ,s.rect);
        sfSprite_setScale(s.sprite, s.scale);
        sfSprite_setPosition(s.sprite, s.pos);
        ALL->speed = ALL->speed * 0.8;
        ALL->bird_nbr += 1;
    }
}

void init (GLOBAL_T *ALL)
{
    ALL->best_score = 0;
    init_window(ALL);
    init_sprite(ALL);
    init_main_menu(ALL);
    init_var(ALL);
    init_text(ALL);
    init_bird(ALL);
    init_cursor(ALL);
}
