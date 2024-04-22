/*
** EPITECH PROJECT, 2022
** do op
** File description:
** do op
*/

#include "../include/my.h"

int get_op(int code, int fir, int sec, int result)
{
    if (code == 1) {
        result = fir + sec;
        my_put_nbr(result);
    }
    if (code == 2) {
        result = fir - sec;
        my_put_nbr(result);
    }
    if (code == 3) {
        result = fir / sec;
        my_put_nbr(result);
    }
    if (code == 4) {
        result = fir * sec;
        my_put_nbr(result);
    }
    if (code == 5) {
        result = fir % sec;
        my_put_nbr(result);
    }
}

int do_op(int fir, char **op, int sec)
{
    int code, res = 0;

    if (op[2][0] == '+')
        get_op(code = 1, fir, sec, res);
    if (op[2][0] == '-')
        get_op(code = 2, fir, sec, res);
    if (op[2][0] == '/')
        get_op(code = 3, fir, sec, res);
    if (op[2][0] == '*')
        get_op(code = 4, fir, sec, res);
    if (op[2][0] == '%')
        get_op(code = 5, fir, sec, res);
}

int main(int ac, char **av)
{
    if (ac != 4 || ac == 1 || ac == 3)
        return 84;
    int fir = my_getnbr(av[1]);
    int sec = my_getnbr(av[3]);
    if (sec == 0 && av[2][0] == '/') {
        my_putstr("Stop: division by zero\n");
        return 84;
    }
    if (sec == 0 && av[2][0] == '%') {
        my_putstr("Stop: modulo by zero\n");
        return 84;
    }
    if (ac == 4) {
        do_op(fir, av, sec);
        my_putchar('\n');
    }
    return 0;
}
