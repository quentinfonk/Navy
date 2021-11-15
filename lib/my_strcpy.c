/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** task01_d6
*/

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    if (src[i] == '\0')
        dest[i] = '\0';
    return (dest);
}
