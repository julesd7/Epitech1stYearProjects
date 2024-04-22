/*
** EPITECH PROJECT, 2022
** rush 1-1
** File description:
** rush 1-1
*/

int get_high_low(int x)
{
    int i = 1;
    my_putchar('o');
    while (i < x - 1) {
        my_putchar('-');
        i++;
    }
    if (x > 1)
        my_putchar('o');

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
    if (y <= 1)
        return;
    my_putchar('\n');
    while (saveIndex > 0) {
        my_putchar('|');
        indexX = ixs;
        space_for_y(indexX, x);
        if (x > 1)
            my_putchar('|');
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
    get_high_low(x);
    get_sides(y, x);
    if (y > 1)
        get_high_low(x);
}
