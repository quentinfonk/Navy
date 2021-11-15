/*
** EPITECH PROJECT, 2020
** send
** File description:
** send
*/

#include "my.h"

void send_touch(int i, int pid)
{
    usleep(2000);
    if (i == 1)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    return;
}

static void handler3(int sig, siginfo_t *info, void *ucontext)
{
    info->si_pid;
    if (sig == SIGUSR1)
        sig_nb = 1;
    else
        sig_nb = 2;
}

int recep_touch(void)
{
    struct sigaction sig;

    sigemptyset(&sig.sa_mask);
    sig.sa_sigaction = &handler3;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pause();
    return (sig_nb);
}
