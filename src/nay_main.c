/*
** EPITECH PROJECT, 2020
** navy
** File description:
** *
*/

#include "my.h"

void print_turn(char **tab_map, char **tab_enm)
{
    my_putstr("my positions:\n");
    for (int i = 0; tab_map[i] != NULL; i++)
        my_putstr(tab_map[i]);
    my_putstr("\nenemy’s positions:\n");
    for (int i = 0; tab_enm[i] != NULL; i++)
        my_putstr(tab_enm[i]);
    my_putchar('\n');
}

int game_loop(char **tab_map, char **tab_enm, int pid, int pid2)
{
    int i = 0;

    while (42) {
        print_turn(tab_map, tab_enm);
        if ((tab_enm = player_1_turn(tab_map, tab_enm, pid2)) == NULL)
            return 84;
        i = check_win(tab_map, tab_enm);
        if (i != -1)
            return 1;
        else if (i == 0)
            return (0);
        if ((tab_map = player_2_turn(tab_map, tab_enm, pid2)) == NULL)
            return 84;
        i = check_win(tab_map, tab_enm);
        if (i != -1)
            return 1;
        else if (i == 0)
            return (0);
    }
    return 1;
}

int game_loop_2(char **tab_map, char **tab_enm, int pid, int pid2)
{
    int i = -1;

    while (42) {
        print_turn(tab_map, tab_enm);
        if ((tab_map = player_2_turn(tab_map, tab_enm, pid)) == NULL)
            return 84;
        i = check_win(tab_map, tab_enm);
        if (i != -1)
            return 1;
        else if (i == 0)
            return (0);
        if ((tab_enm = player_1_turn(tab_map, tab_enm, pid)) == NULL)
            return 84;
        i = check_win(tab_map, tab_enm);
        if (i != -1)
            return 1;
        else if (i == 0)
            return (0);
    }
    return 0;
}

int nay_main(int ac, char **av, int pid, int pid2)
{
    char **tab_map = create_map();
    char **tab_enm = create_map();

    if (tab_map == NULL || tab_enm == NULL)
        return (84);
    if (ac == 2) {
        if (get_inp(tab_map, av, ac) == 84)
            return (84);
        pid = sig_1(ac, av);
        pid2 = sig_nb;
        return (nay(tab_map, tab_enm, pid, pid2));
    }
    else if (ac == 3) {
        if (get_inp(tab_map, av, ac) == 84)
            return (84);
        pid2 = sig_2(ac, av);
        pid = my_getnbr(av[1]);
        return (nay_2(tab_map, tab_enm, pid, pid2));
    }
    return 0;
}
