/*
** EPITECH PROJECT, 2022
** my print comb 2
** File description:
** display in ascending order all combinaison of two two-digit numbers
*/

void show(int n)
{
    char n1 = (n / 10) + 48;
    char n2 = (n % 10) + 48;
    my_putchar(n1);
    my_putchar(n2);
}

void verif(int g, int d)
{
    if (g != 98 || d != 99) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    int g = 0;
    int d = 1;
    while (g < 99) {
        d = g + 1;
        while (d < 100) {
            show(g);
            my_putchar(' ');
            show(d);
            verif(g, d);
            d++;
        }
        g++;
    }
}
