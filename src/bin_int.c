/*
** EPITECH PROJECT, 2020
** bin
** File description:
** int
*/

int bin_int(char *str)
{
    int a = 0;

    if (str[2] == '1')
        a += 1;
    if (str[1] == '1')
        a += 2;
    if (str[0] == '1')
        a += 4;
    return (a);
}
