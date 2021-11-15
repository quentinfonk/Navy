/*
** EPITECH PROJECT, 2020
** get_map
** File description:
** *
*/

#include "my.h"

char **feel_coll(char *buff, char **tab_map)
{
    int size = (NBR(buff[6]) - NBR(buff[3]) + 1);
    int coll = (LETTER(buff[2]) * 2 + 2);

    if (coll %2 != 0)
        coll++;
    for (int i = (NBR(buff[3]) + 1), j = 0; j < size ; i++, j++) {
        if (tab_map[i][coll] != '.')
            return NULL;
        tab_map[i][coll] = buff[0];
    }
    return tab_map;
}

char **feel_line(char *buff, char **tab_map)
{
    int size = (LETTER(buff[5]) - LETTER(buff[2]) + 1);
    int line = (NBR(buff[3]) + 1);

    for (int i = ((LETTER(buff[2]) * 2) + 2), j = 0; j < size ; i++, j++) {
        if (i % 2 != 0)
            i+=1;
        if (tab_map[line][i] != '.')
            return NULL;
        tab_map[line][i] = buff[0];
    }
    return tab_map;
}

char **feel_navy(char *buff, char **tab_map)
{
    if (LETTER(buff[2]) - LETTER(buff[5]) == 0) {
        if ((tab_map = feel_coll(buff, tab_map)) == NULL)
            return NULL;
    }
    else if (LETTER(buff[3]) - LETTER(buff[6]) == 0)
        if ((tab_map = feel_line(buff, tab_map)) == NULL)
            return NULL;
    return tab_map;
}

int check_nb(int arg, char *buff)
{
    if (arg == 0)
        if (NBR(buff[0]) != 2)
            return 84;
    if (arg == 1)
        if (NBR(buff[0]) != 3)
            return 84;
    if (arg == 2)
        if (NBR(buff[0]) != 4)
            return 84;
    if (arg == 3)
        if (NBR(buff[0]) != 5)
            return 84;
    return 0;
}

int error_set_map(char *buff)
{
    static int arg = 0;

    if ((buff[1] & buff[4]) != 58)
        return 84;
    if (check_nb(arg, buff) == 84)
        return 84;
    if (LETTER(buff[2]) - LETTER(buff[5]) == 0) {
        if (NBR(buff[6]) - NBR(buff[3]) != (NBR(buff[0]) - 1))
            return 84;
    }
    else if (NBR(buff[3]) - NBR(buff[6]) == 0) {
        if (LETTER(buff[5]) - LETTER(buff[2]) != (NBR(buff[0]) - 1))
            return 84;
    }
    else
        return 84;
    arg += 1;
    if (arg > 3)
        arg = 0;
    return 0;
}
