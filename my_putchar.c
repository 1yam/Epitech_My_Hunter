/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-lyam.gomes
** File description:
** my_putchar.c
*/
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
