/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

int check_hit(char *buff, char **tab_map)
{
    int coll = 0;
    int line = 0;

    for (int i = 0; i < 8; i++)
        if (buff[0] == (i+65)) {
            coll = 1;
            break;
        }
        else
            coll = 0;
    for (int i = 0; i < 8; i++)
        if (buff[1] == (i+49)) {
            line = 1;
            break;
        }
        else
            line = 0;
    if ((coll == 0) || (line == 0))
        return -1;
    return 0;
}

int check_line(char tab_map, char tab_enm, int win)
{
    if (tab_map == '1' || tab_map == '2' ||
        tab_map == '3' || tab_map == '4' ||
        tab_map == '5' || tab_map == '6' ||
        tab_map == '7' || tab_map == '8')
        win++;
    return (win);
}

int check_line2(char tab_map, char tab_enm, int lose)
{
    if (tab_enm == 'x')
        lose++;
    return (lose);
}

int check_win(char **tab_map, char **tab_enm)
{
    int win = 0;
    int lose = 0;

    for (int i = 2; tab_map[i] != NULL; i++)
        for (int j= 2; tab_map[i][j] != '\n'; j++) {
            win = check_line(tab_map[i][j], tab_enm[i][j], win);
            lose = check_line2(tab_map[i][j], tab_enm[i][j], lose);
        }
    if (lose == 14) {
        my_putstr("I won\n");
        return 0;
    }
    if (win == 0) {
        my_putstr("Enemy won\n");
        return 42;
    }
    return -1;
}
