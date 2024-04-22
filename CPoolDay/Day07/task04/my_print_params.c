/*
** EPITECH PROJECT, 2022
** print param
** File description:
** print param
*/

int my_putstr(char const *str);

void my_putchar(char c);

int my_print_params(int argc, char *argv[])
{
    int i = 0;

    while (i < argc) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int argc, char *argv[])
{
    my_print_params(argc, argv);
    return 0;
}
