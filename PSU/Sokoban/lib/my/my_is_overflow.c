/*
** EPITECH PROJECT, 2022
** my is overflow
** File description:
** returns 1 if overflow
** else return 0
*/

#include "my.h"

int my_is_overflow(long verify, long calc)
{
    return verify * calc != (int)((int)verify * (int)calc);
}
