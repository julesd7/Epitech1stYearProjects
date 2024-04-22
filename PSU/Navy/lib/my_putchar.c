/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

#include "../include/lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
