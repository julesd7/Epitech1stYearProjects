/*
** EPITECH PROJECT, 2022
** rush 1-5
** File description:
** rush 1-5
*/

int get_high(int x, int y)
{
    int i = 1;
    if (y > 1 && x > 1) {
        my_putchar('A');
    } else {
        my_putchar('B');
    }
    while (i < x - 1) {
        my_putchar('B');
        i++;
    }
    if (x > 1) {
        if (y > 1) {
            my_putchar('C');
        } else {
            my_putchar('B');
        }
    }
}

int get_low(int x, int y)
{
    int i = 1;
    if (y > 1 && x > 1) {
        my_putchar('C');
    } else {
        my_putchar('B');
    }
    while (i < x - 1) {
        my_putchar('B');
        i++;
    }
    if (x > 1) {
        my_putchar('A');
    }
}

int space_for_y(int indexX, int x)
{
    if (x > 1) {
        while (indexX > 0) {
            my_putchar(' ');
            indexX--;
        }
    }
}

int get_sides(int y, int x)
{
    int indexX = x - 2;
    int saveIndex = y - 2;
    int ixs = indexX;
    if (y <= 1) {
        return;
    }
    my_putchar('\n');
    while (saveIndex > 0) {
        my_putchar('B');
        indexX = ixs;
        space_for_y(indexX, x);
        if (x > 1) {
            my_putchar('B');
        }
        my_putchar('\n');
        saveIndex--;
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0){
        write(2, "Invalid size\n", 13);
        return 0;
    }
    get_high(x, y);
    get_sides(y, x);
    if (y > 1)
        get_low(x, y);
}
