/*
** EPITECH PROJECT, 2022
** my print comb
** File description:
** display il ascending order all number (3 digits)
*/

void push(int a, int b, int c)
{
    my_putchar(48 + a);
    my_putchar(48 + b);
    my_putchar(48 + c);
    my_putchar(',');
    my_putchar(' ');
}

void  push_without_com(int a, int b, int c)
{
    my_putchar(48 + a);
    my_putchar(48 + b);
    my_putchar(48 + c);
}

int my_print_comb(void)
{
    int a = 0;
    int b = 1;
    int c = 2;
    while (a != 7) {
        push(a, b ,c);
        c++;
        if (c == 9) {
            push(a, b, c);
            b++;
            c = b + 1;
        }
        if (b == 8) {
            push(a, b, c);
            a++;
            b = a + 1;
            c = b + 1;
        }
    }
    push_without_com(a, b, c);
}
