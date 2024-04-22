/*
** EPITECH PROJECT, 2022
** test my_strcpy
** File description:
** tests
*/

#include <criterion/criterion.h>
Test (my_strcpy, copy_HelloWorld) {
    char dest[11] = {0};
    my_strcpy (dest, "HelloWorld");
    cr_assert_str_eq(dest, "HelloWorld");
}

Test (my_strcpy, copy_Hello) {
    char dest[6] = {0};
    my_strcpy (dest, "Hello");
    cr_assert_str_eq(dest, "Hello");
}
