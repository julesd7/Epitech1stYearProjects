/*
** EPITECH PROJECT, 2022
** my getnbr
** File description:
** return a number, sent as a string
*/

int iserror(int nb, int neg)
{
    int to_test = nb;
    if (neg == -1)
        to_test--;
    if (to_test < 0) {
        return 1;
    } else {
        return 0;
    }
}

int my_getnbr(char const *str)
{
    int nbr = 0 ;
    int negver = 1;
    int i = 0;
    int verifiserror = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            negver *= -1;
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = (nbr * 10) + str[i] - '0';
            verifiserror = iserror(nbr, negver);
        }
        if (verifiserror)
            return 0;
        if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
            return (nbr * negver);
        i++;
    }
    return (nbr * negver);
}
