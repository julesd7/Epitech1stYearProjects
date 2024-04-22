/*
** EPITECH PROJECT, 2022
** rush-1-4
** File description:
** c
*/

int rush_length_one(int x, int y)
{
    int i_l = 1;
    if (x > 1 && y > 1){
        write(1, "A", 1);
    } else {
        write(1, "B", 1);
    }
    while (i_l < x - 1){
        write(1, "B", 1);
        i_l++;
        }
    if (x > 1){
        if (y > 1){
            write(1, "C", 1);
        } else {
            write (1, "B", 1);
        }
    }
}

int rush_length_two(int x, int y)
{
    int i_m = 1;
    if (y > 1 && x > 1){
        write(1, "A", 1);
    } else {
        write(1, "B", 1);
    }
    while (i_m < x - 1){
        write(1, "B", 1);
        i_m++;
        }
    if (x > 1){
    write(1, "C", 1);
    }
}

int before_space(int x, int y)
{
    int i_s = 0;
    if (x > 1){
        while (i_s < x - 2){
        write(1, " ", 1);
        i_s++;
    }
        write(1, "B", 1);
    }
}

int rush_height(int x, int y)
{
    int i_t = 1;
    while (i_t <= y - 2){
        write(1, "\n", 1);
        write(1, "B", 1);
        if (y > 1){
            before_space(x, y);
            i_t++;
        }
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return 0;
    }
    rush_length_one(x, y);
    rush_height(x, y);
    write(1, "\n", 1);
    if (y > 1){
        rush_length_two(x, y);
    }
}
