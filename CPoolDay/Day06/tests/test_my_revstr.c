/*
** EPITECH PROJECT, 2022
** test my revstr
** File description:
** tests
*/

#include <criterion/criterion.h>

Test(my_revstr, testrevstr) {
    char dest[] = "Hello";
    my_revstr(dest);
    cr_assert_str_eq(dest, "olleH");
}
