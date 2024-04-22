/*
** EPITECH PROJECT, 2022
** fonctions
** File description:
** fonctions
*/

int change_bot_star(int size, int space, int spbefore, int spacesave)
{
    int save = spbefore;
    for (size; size > 1; size--) {
        for (spbefore; spbefore > 0; spbefore--) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (space; space > 0; space--) {
            my_putchar(' ');
        }
        write(1, "*\n", 2);
        spbefore = save + 1;
        save = spbefore;
        space = spacesave - 2;
        spacesave = space;
    }
}

int change_top_star(int size, int midgauche, int midDroit, int mid)
{
    for (mid; mid > 0; mid--) {
        my_putchar(' ');
    }
    write(1, "*\n", 2);
    for (size; size > 1; size--) {
        for (mid; mid < midgauche; mid++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (mid; mid < midDroit; mid ++) {
            my_putchar(' ');
        }
        midgauche--;
        midDroit++;
        mid = 0;
        write(1, "*\n", 2);
    }
}

int second_change_midstar(int size, int mid, int start, int space)
{
    for (size; size > 1; size--) {
        for (int verif = 0; verif < start; verif++) {
            my_putchar(' ');
        }
        start--;
        my_putchar('*');
        for (space = 2; space < mid; space++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
        mid = mid + 2;
    }

}

void use_space_bis(int start)
{
    for (int verif = 0; verif < start; verif++) {
        my_putchar(' ');
    }
}

void use_space(int mid)
{
    for (int i = 2; i < mid; i++) {
            my_putchar(' ');
    }
}
