/*
** EPITECH PROJECT, 2022
** my_show_param_array
** File description:
** show param array
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_put_nbr(int nb);

static int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != '\0') {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].str = 0; i++) {
        my_put_nbr(par[i].length);
        my_putstr(par[i].str);
        my_putstr(par[i].copy);
        my_show_word_array(par[i].word_array);
    }
}
