/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_game.h
*/

#ifndef _my_game_
    #define _my_game_
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Audio.h>

    #define windows ALL->settings.window
    #define modes ALL->settings.mode
    #define nb ALL->settings.img_n
    #define s ALL->b[nb]
    #define text ALL->texture
    #define sa ALL->b[i]
    #define cur ALL->cursor

    typedef struct PARAMETER {
        sfVideoMode mode;
        sfRenderWindow* window;
        sfEvent event;
        int img_n;
    } PARAMETER_T;

    typedef struct IMG {
        sfTexture *texture;
        sfClock* anim;
        sfClock* mov_time;
        float speed;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
        sfVector2f size;
        sfVector2f origin;
        sfBool state;
        sfIntRect rect;
        int move_pixel;
    } IMG_T;

    typedef struct cursor {
        sfTexture *texture;
        sfSprite* sprite;
        sfVector2f size;
    } CURSOR_T;

    typedef struct my_diff_bird {
        char** path;
    } texture;

    typedef struct GLOBAL {
        PARAMETER_T settings;
        IMG_T *b;
        IMG_T m;
        CURSOR_T cursor;
        texture texture;
        sfText* ammo;
        sfText* t_ammo;
        sfText* t_score;
        sfText* t_hp;
        sfFont* font;
        sfMusic* music;
        int score;
        int best_score;
        int grade;
        int hp;
        int nbr_img;
        int touched;
        int rotations;
        int nbr_ammo;
        float speed;
        int bird_nbr;
        sfBool game_launched;
    } GLOBAL_T;

    #define sfCf sfTexture_createFromFile
    #define sfWc sfRenderWindow_create
    #define WINDOW ALL->settings.window
    #define EVENT ALL->settings.event
    #define IMG ALL->b

    int init_var(GLOBAL_T *ALL);
    void init (GLOBAL_T *ALL);
    sfIntRect get_rect(int top, int left, int width, int height);
    int move_bird(GLOBAL_T *ALL);
    void analyse_events(sfRenderWindow *window, sfEvent event, GLOBAL_T *ALL);
    int get_distance(sfVector2f coords_1, sfVector2f coords_2);
    int get_distance_2(sfVector2f coords_1, sfVector2f coords_2);
    int shot(GLOBAL_T *ALL);
    int game_update(GLOBAL_T *ALL);
    float float_rand(float min, float max);
    int init_main_menu(GLOBAL_T *ALL);
    char *int_to_char(int nbr);
    int number_digits(int nbr);
    int my_game_h(void);
    int init_cursor(GLOBAL_T *ALL);
    int update_crosshair(GLOBAL_T *ALL);
    int sound(GLOBAL_T *ALL);
    void init_text(GLOBAL_T *ALL);
    void update_text(GLOBAL_T *ALL);
#endif
