/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** *
*/

#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <sys/types.h>

#ifndef MY_H
#define MY_H

#define ASCII(a) (a + '0')
#define NBR(a) (a - '0')
#define LETTER(a) (a - 'A')

int sig_nb;

int nay_main(int ac, char **av, int pid, int pid2);
void my_putchar(char c);
void my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
char *my_revstr(char *str);
void my_putnbr(int nb);
int bin_int(char *str);
char *my_strcpy(char *dest, char *src);
char *feel_tab(char *buff, char **tab_arg, int table);
char **set_map(char const *filepath);
char **create_map(void);
char **feel_navy(char *buff, char **tab_map);
int error_set_map(char *buff);
char **get_input(char **tab_map, char **av, int ac);
void send_touch(int i, int pid);
int recep_touch(void);
int sig_1(int ac, char **av);
int sig_2(int ac, char **av);
char *fct_b(int i);
void send(int env, int pid);
int recep(int pid);
int check_win(char **tab_map, char **tab_enm);
void print_turn(char **tab_map, char **tab_enm);
char **place_hit_2(char *buff, char **tab_map, char **tab_enm, int pid);
char **place_hit(char *buff, char **tab_map, char **tab_enm, int pid);
int check_hit(char *buff, char **tab_map);
char **player_1_turn(char **tab_map, char **tab_enm, int pid);
char **player_2_turn(char **tab_map, char **tab_enm, int pid);
int check_hit(char *buff, char **tab_map);
int check_win(char **tab_map, char **tab_enm);
int nay(char **tab_map, char **tab_enm, int pid, int pid2);
int nay_2(char **tab_map, char **tab_enm, int pid, int pid2);
int game_loop(char **tab_map, char **tab_enm, int pid, int pid2);
int game_loop_2(char **tab_map, char **tab_enm, int pid, int pid2);
int get_inp(char **tab_map, char **av, int ac);

#endif
