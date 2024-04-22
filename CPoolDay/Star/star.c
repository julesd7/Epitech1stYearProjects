/*
** EPITECH PROJECT, 2022
** star
** File description:
** Write a function that displays a star, based on its given size.
*/

int get_topstar(int size)
{
    int space = 1;
    int mid = 5;
    int save = size;
    int midDroit;
    int midgauche;
    int savemid;
    for (size; size > 2; size--) {
        space = space + 2;
    }
    size = save;
    for (size; size > 2; size --) {
        mid = mid + 2;
    }
    size = save;
    mid = ((mid * 2) + space) / 2;
    savemid = mid;
    midgauche = mid - 1;
    midDroit = mid;
    change_top_star(size, midgauche, midDroit, mid);
    return (savemid);
}

void get_barstar(int size)
{
    int space = 1;
    int bar = 5;
    int save = size;
    for (save; save > 2; save--) {
        space = space + 2;
    }
    for (size; size > 2; size --) {
        bar = bar + 2;
    }
    save = bar;
    for (bar; bar > 0; bar--) {
        my_putchar('*');
    }
    for (space; space > 0; space--) {
        my_putchar(' ');
    }
    bar = save;
    for (bar; bar > 0; bar--) {
        my_putchar('*');
    }
}

void get_midstar(int size)
{
    int space = 1, bar = 5, save = size, mid, lastsave = size, start = 1;
    for (size; size > 2; size--)
        space = space + 2;
    size = save;
    for (size; size > 2; size --)
        bar = bar + 2;
    mid = ((bar * 2) + space) - 2;
    size = lastsave;
    for (size; size > 0; size--) {
        use_space_bis(start);
        start++;
        my_putchar('*');
        use_space(mid);
        write(1, "*\n", 2);
        mid = mid - 2;
    }
    size = lastsave;
    start = start - 2;
    mid = mid + 4;
    second_change_midstar(size, mid, start, mid);
}

void get_botstar(int size, int mid)
{
    int space = 1;
    int spbefore = 5;
    int save = size;
    int spacesave;
    for (size; size > 2; size--) {
        space = space + 2;
    }
    spacesave = space;
    size = save;
    for (size; size > 2; size --) {
        spbefore = spbefore + 2;
    }
    spbefore--;
    size = save;
    save = spbefore;
    change_bot_star(size, space, spbefore, spacesave);
    for (mid; mid > 0; mid--) {
        my_putchar(' ');
    }
    write(1, "*\n", 2);
}

void star(unsigned int size)
{
    if (size == 0)
        return 0;
    if (size == 1) {
        write(1, "   *\n", 5);
        write(1, "*** ***\n", 8);
        write(1, " *   *\n", 7);
        write(1, "*** ***\n", 8);
        write(1, "   *\n", 5);
    }
    if (size > 1) {
        int savemid = get_topstar(size);
        get_barstar(size);
        my_putchar('\n');
        get_midstar(size);
        get_barstar(size);
        my_putchar('\n');
        get_botstar(size, savemid);
    }
}
