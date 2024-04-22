/*
** EPITECH PROJECT, 2022
** test my strncpy
** File description:
** tests
*/

#include <criterion/criterion.h>
Test (my_strncpy, copy_five_characters_in_empty_array) {
    char dest[6] = {0};
    my_strncpy (dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test (my_strncpy, i_egal_to_n) {
    char dest[6] = {0};
    my_strncpy (dest, "Hello", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test (my_strncpy, i_inf_to_n) {
    char dest[24] = {0};
    my_strncpy(dest, "HelloAAAAAAA", 24);
    cr_assert_str_eq(dest, "HelloAAAAAAA");
}
