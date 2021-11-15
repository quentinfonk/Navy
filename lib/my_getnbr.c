/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** task05 day 4
*/

int my_getnbr(char *str)
{
    int start = 0, puissance = 1, r = 0, final = 0, neg = 1;
    
    for (; '9' < str[r] || str[r] < '0'; r++) {
        start = r;
        if (str[r] == '\0')
            return (0);
    }
    if (str[r] == '\0')
        return (0);
    if (str[start - 1] == '-')
        neg = -1;
    for (; '0' <= str[r] && str[r] <= '9'; r++) {
        puissance = puissance * 10;
        if (r - start > 10)
            return (0);
    }
    for (; puissance != 1; puissance = puissance / 10, start++)
        final = final + ((str[start] - 48) * puissance);
    return ((final / 10) * neg);
}
