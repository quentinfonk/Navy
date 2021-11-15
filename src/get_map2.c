/*
** EPITECH PROJECT, 2020
** get_map
** File description:
** 2
*/

#include "my.h"

int check_f(char *str)
{
    static int a = 0;

    if (my_strlen(str) != 180 && a == 0)
        my_putstr("Bad map\n");
    a++;
    if (my_strlen(str) != 180)
        return (84);
    return (0);
}

char **create_map(void)
{
    char **map_tab = malloc(sizeof(char*) * (10 + 1));
    char *buff = malloc(sizeof(char) * (180 + 1));
    int opn = open("map/map.txt", O_RDONLY);
    int rd = read(opn, buff, 181);
    int i = 0;
    int j = 0;
    int count = 0;

    if (check_f(buff) == 84)
        return NULL;
    for (i = 0; i < 10; i++) {
        map_tab[i] = malloc(sizeof(char) * (17 + 1));
        for (j = 0; buff[count] != '\n' && buff[count] != '\0'; count++, j++) {
            map_tab[i][j] = buff[count];
        }
        map_tab[i][j] = '\n';
        count++;
    }
    map_tab[i] = NULL;
    free(buff);
    return map_tab;
}
