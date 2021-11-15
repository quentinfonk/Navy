/*
** EPITECH PROJECT, 2020
** com
** File description:
** com
*/

#include "my.h"

char *str_get(char *str)
{
    size_t len = 0;
    ssize_t read;

    str = NULL;
    read = getline(&str, &len, stdin);
    if (str[0] == '\0')
        return (NULL);
    return (str);
}

char *checknb(char *str)
{
    int a = my_strlen(str);
    char *stack = malloc(sizeof(char) * 4);
    int i = 0;

    if (a != 3)
        for (; a != 3; a++, i++)
            stack[i] = '0';
    else
        return (str);
    for (a = 0; str[a] != '\0'; a++, i++)
        stack[i] = str[a];
    return (stack);
}

void send(int env, int pid)
{
    int i = 0;
    char *str;

    str = fct_b(env);
    str = checknb(str);
    str = my_revstr(str);
    for (int a = 0; a != 3; a++) {
        if (str[a] == '1')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1000);
        i++;
    }
}

static void handler2(int sig, siginfo_t *info, void *ucontext)
{
    info->si_pid;
    if (sig == SIGUSR1)
        sig_nb = 1;
    else
        sig_nb = 0;
}

int recep(int pid)
{
    struct sigaction sig;
    char *str = malloc(sizeof(char) * 3+1);

    sigemptyset(&sig.sa_mask);
    sig.sa_sigaction = &handler2;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    for (int a = 0; a != 3; a++) {
        pause();
        str[a] = sig_nb + 48;
    }
    my_revstr(str);
    return (bin_int(str));
}
