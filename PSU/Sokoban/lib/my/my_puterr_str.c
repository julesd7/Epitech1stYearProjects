/*
** EPITECH PROJECT, 2022
** put str in error
** File description:
** str in error
*/

#include <unistd.h>
#include "my.h"

int my_puterr_str(char const *str)
{
    int nbc = 0;

    while (str[nbc] != '\0') {
        write(2, &str[nbc], 1);
        nbc++;
    }
    return 0;
}
