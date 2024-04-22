/*
** EPITECH PROJECT, 2022
** test my strncat
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, my_strncat_a) {
    char dest[] = "Hey, ";
    my_strncat(dest, "howru fine thx", 5);
    cr_assert_str_eq(dest, "Hey, howru");
}
