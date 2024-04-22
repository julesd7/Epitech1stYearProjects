/*
** EPITECH PROJECT, 2022
** my rev params
** File description:
** my rev params
*/

int my_putstr(char const *str);

void my_putchar(char c);

int my_rev_params(int argc, char *argv[])
{
    int i = argc - 1;

    while (i > -1) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i--;
    }
}

int main(int argc, char *argv[])
{
    my_rev_params(argc, argv);
    return 0;
}
