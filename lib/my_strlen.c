/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** 3rd program
*/

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
