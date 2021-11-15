/*
** EPITECH PROJECT, 2020
** nay
** File description:
** nay
*/

#include "my.h"

int nay(char **tab_map, char **tab_enm, int pid, int pid2)
{
    int test = 0;

    return (game_loop(tab_map, tab_enm, pid, pid2));
}

int nay_2(char **tab_map, char **tab_enm, int pid, int pid2)
{
    int test;

    return (game_loop_2(tab_map, tab_enm, pid, pid2));
}
