/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

#include "my.h"

void print_msg(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions");
    my_putstr("\nDESCRIPTION\n\tfirst_player_pid: only for the 2nd player");
    my_putstr(". pid of the first player.\n\tnavy_positions: file ");
    my_putstr("representing the positions of the ships.\n");
}

void main(int ac, char **av)
{
    int pid = 0;
    int pid2 = 0;

    if (ac == 2 && av[1][0] == '-')
        if (av[1][1] == 'h' && av[1][2] == '\0') {
            print_msg();
            return;
        }
    nay_main(ac, av, pid, pid2);
}
