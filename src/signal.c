/*
** EPITECH PROJECT, 2020
** signal
** File description:
** signal
*/

#include "my.h"

static void handler1(int sig, siginfo_t *info, void *ucontext)
{
    info->si_pid;
    sig_nb = info->si_pid;
}

int sig_1(int ac, char **av)
{
    struct sigaction sig;
    int pid = 0;

    my_putstr("my_pid: ");
    pid = getpid();
    printf("%d\n", pid);
    my_putstr("waiting for enemy connection...\n\n");
    sigemptyset(&sig.sa_mask);
    sig.sa_sigaction = &handler1;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pause();
    my_putstr("enemy connected\n\n");
    return (pid);
}
