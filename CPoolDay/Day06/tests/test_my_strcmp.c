/*
** EPITECH PROJECT, 2022
** test my_strcmp
** File description:
** tests
*/

#include <criterion/criterion.h>

Test(my_strcmp, my_strcmp_greater) {
    char s1[] = "Hello";
    char s2[] = "Hell";
    int verif = my_strcmp(s1, s2);
    cr_assert_eq(verif, 1);
}

Test(my_strcmp, my_strcmp_lower) {
    char s1[] = "Hell";
    char s2[] = "Hello";
    int verif = my_strcmp(s1, s2);
    cr_assert_eq(verif, -1);
}

Test(my_strcmp, my_strcmp_egals) {
    char s1[] = "Hello";
    char s2[] = "Hello";
    int verif = my_strcmp(s1, s2);
    cr_assert_eq(verif, 0);
}
