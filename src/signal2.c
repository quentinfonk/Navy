/*
** EPITECH PROJECT, 2020
** signal_2
** File description:
** signal2
*/

#include "my.h"

int sig_2(int ac, char **av)
{
    int pid = my_getnbr(av[1]);
    int pid2 = 0;

    my_putstr("my_pid: ");
    pid2 = getpid();
    printf("%d\n", pid2);
    kill(pid, SIGUSR1);
    my_putstr("successfully connected\n\n");
    return (pid2);
}
