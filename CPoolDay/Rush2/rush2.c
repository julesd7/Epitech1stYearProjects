/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** rush2
*/
#include <stdio.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_strlen(char const *str);

int print_the_result(int occ, int j, char **argv)
{
    write(1, argv[j], 1);
    write(1, ":", 1);
    my_put_nbr(occ);
}

int verify_these_numbers(int occ, char **argv, int i, int j)
{
    if (argv[j][0] >= 'A' && argv[j][0] <= 'Z') {
        if (argv[j][0] == argv[1][i] || argv[j][0] == argv[1][i] - 32) {
            occ++;
        }
    }
    if (argv[j][0] >= 'a' && argv[j][0] <= 'z') {
        if (argv[j][0] == argv[1][i] || argv[j][0] == argv[1][i] + 32) {
            occ++;
        }
    }
    return occ;
}

int get_percentage(int occ, char **argv)
{
    int len = my_strlen(argv[1]);
    int getnb = (occ * 10000) / len;
    int first = getnb / 100;
    int sec = getnb % 100;

    write(1, " (", 2);
    my_put_nbr(first);
    my_putchar('.');
    if (sec == 0) {
        my_put_nbr(sec);
        my_putchar('0');
    } else
        my_put_nbr(sec);
    write(1, "%)", 2);
    my_putchar('\n');
}

int counting_occurences(int argc, char **argv)
{
    int occ = 0, j = 2;
    while (argc > j) {
        for (int i = 0; argv[1][i]; i++) {
            occ = verify_these_numbers(occ, argv, i, j);
        }
        print_the_result(occ, j, argv);
        get_percentage(occ, argv);
        j++;
        occ = 0;
    }
    return (occ);
}

int main(int argc, char **argv)
{
    counting_occurences(argc, argv);
    return 0;
}
