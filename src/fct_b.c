/*
** EPITECH PROJECT, 2019
** fct_b
** File description:
** fct_b
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

char *bina(int i, char *str)
{
    int a = 0;

    for (; i != 0; a++) {
        str[a] = (i%2) + '0';
        i = i / 2;
    }
    str[a] = '\0';
    return (str);
}

char *fct_b(int i)
{
    char *str;
    int o = 0;
    int c = i;

    if (i == 0) {
        str = malloc(sizeof(char) * 1+1);
        str[0] = '0';
        return (str);
    }
    for (;i != 0; o++)
        i = i / 2;
    i = c;
    str = malloc(sizeof(char) * (o + 1));
    if (str == NULL)
        return (NULL);
    str = bina(i, str);
    my_revstr(str);
    return (str);
}
