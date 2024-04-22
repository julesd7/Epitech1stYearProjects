/*
** EPITECH PROJECT, 2022
** mini printf
** File description:
** mini printf
*/

#include <stdarg.h>
#include <unistd.h>

int my_putstr(char const *str);

int my_putchar(char c);

int my_putnbr(int nb);

static int print_char(char c)
{
    write(1, &c, 1);
    return 0;
}

static int print_int(int i)
{
    int c;
    c = my_putnbr(i);
    return c;
}

static int print_str(char *s)
{
    my_putstr(s);
    int nbcount = 0;
    while (s[nbcount] != '\0') {
        nbcount++;
    }
    return nbcount;
}

int get_flags(const char *format, va_list list)
{
    int c = 0;
    switch (*format) {
        case 's':
            c = c + print_str(va_arg(list, char *));
            break;
        case 'd':
        case 'i':
            c = c + print_int(va_arg(list, int));
            break;
        case 'c':
            print_char(va_arg(list, int));
            c++;
            break;
        case '%':
        default:
            c += write(1, "%", 1);
            break;
    }
    return c;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int c = 0;
    int can_do_next = 0;

    va_start(list, format);
    while (*format) {
        if (*format == '%' && !can_do_next) {
            can_do_next = 1;
            format++;
            continue;
        }
        if (can_do_next) {
            c = c + get_flags(format, list);
            can_do_next = 0;
        } else
            c += write(1, format, 1);
        format++;
    }
    va_end(list);
    return c;
}
