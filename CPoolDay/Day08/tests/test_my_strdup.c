/*
** EPITECH PROJECT, 2022
** test my strdup
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test (my_strdup, copy_HelloWorld) {
    char *hello = my_strdup ("HelloWorld");
    cr_assert_str_eq(hello, "HelloWorld");
}

Test (my_strdup, copy_Hello) {
    char *hello = my_strdup ("Hello");
    cr_assert_str_eq(hello, "Hello");
}
