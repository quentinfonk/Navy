/*
** EPITECH PROJECT, 2020
** my-putchar
** File description:
** 
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int j = 0; str[j] != '\0'; j++)
        my_putchar(str[j]);
}

