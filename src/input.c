/*
** EPITECH PROJECT, 2020
** intu
** File description:
** *
*/

#include "my.h"

char **get_input(char **tab_map, char **av, int ac)
{
    char *buff = malloc(sizeof(char) * 32 + 1);
    char *str = malloc(sizeof(char) * 8);
    int fd = open(av[ac-1], O_RDONLY);
    int rd = read(fd, buff, 33);

    for (int i = 0, j = 0, v = 0; i < 4; i++) {
        str[0] = 0;
        for (v = 0; v <= 7; j++, v++)
            str[v] = buff[j];
        if (error_set_map(str) == 84)
            return NULL;
        if ((tab_map = feel_navy(str, tab_map)) == NULL)
            return NULL;
        v = 0;
    }
    free(buff);
    free(str);
    return tab_map;
}
