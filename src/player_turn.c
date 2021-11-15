/*
** EPITECH PROJECT, 2020
** player_turn
** File description:
** 1
*/

#include "my.h"

char **place_hit_2(char *buff, char **tab_map, char **tab_enm, int pid)
{
    int coll = ((LETTER(buff[0]) * 2) + 1);
    int line = (NBR(buff[1]) + 1);
    int touch = 0;

    if (coll %2 != 0)
        coll++;
    for (int i = 0; i < 2; i++)
        my_putchar(buff[i]);
    if (tab_map[line][coll] == '.' || tab_map[line][coll] == 'x' ) {
        my_putstr(":  missed\n\n");
        tab_map[line][coll] = 'o';
        send_touch(1, pid);
    }
    else {
        my_putstr(":  hit\n\n");
        tab_map[line][coll] = 'x';
        send_touch(2, pid);
    }
    return tab_map;
}

char **place_hit(char *buff, char **tab_map, char **tab_enm, int pid)
{
    int coll = ((LETTER(buff[0]) * 2) + 1);
    int line = (NBR(buff[1]) + 1);
    int touch = 0;

    touch = recep_touch();
    if (coll %2 != 0)
        coll++;
    for (int i = 0; i < 2; i++)
        my_putchar(buff[i]);
    if (touch == 1) {
        tab_enm[line][coll] = 'o';
        my_putstr(":  missed\n\n");
    }
    else if (touch == 2) {
        tab_enm[line][coll] = 'x';
        my_putstr(":  hit\n\n");
    }
    return tab_enm;
}

char **player_1_turn(char **tab_map, char **tab_enm, int pid)
{
    char *buff = NULL;
    size_t size = 0;

    my_putstr("attack:  ");
    if (getline(&buff, &size, stdin) == -1)
        return NULL;
    if (buff[0] == 0)
        return NULL;
    if (check_hit(buff, tab_map) == -1) {
        my_putstr("wrong position\n");
        player_1_turn(tab_map, tab_enm, pid);
        return tab_enm;
    }
    send(LETTER(buff[0]), pid);
    send((NBR(buff[1])-1), pid);
    tab_enm = place_hit(buff, tab_map, tab_enm, pid);
    return tab_enm;
}

char **player_2_turn(char **tab_map, char **tab_enm, int pid)
{
    char *buff = NULL;
    char *temp = malloc(sizeof(char) * (2 + 1));
    size_t size = 0;

    my_putstr("waiting for enemy’s attack...\n");
    temp[0] = (recep(pid) + 'A');
    temp[1] = (recep(pid) + '0'+1);
    temp[2] = 0;
    if (check_hit(temp, tab_map) == -1) {
        my_putstr("wrong position\n");
        player_2_turn(tab_map, tab_enm, pid);
        return tab_map;
    }
    tab_map = place_hit_2(temp, tab_map, tab_enm, pid);
    return tab_map;
}
