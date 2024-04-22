/*
** EPITECH PROJECT, 2022
** test str my isalpha
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test (my_str_isalpha, test_a) {
    char sent[] = "";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isalpha, test_b) {
    char sent[] = "hello";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isalpha, test_c) {
    char sent[] = "HELLO";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isalpha, test_d) {
    char sent[] = "HeLlO";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isalpha, test_e) {
    char sent[] = "hell5";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isalpha, test_f) {
    char sent[] = "h~llo";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isalpha, test_g) {
    char sent[] = "hell]";
    int verif = my_str_isalpha(sent);
    cr_assert_eq(verif, 0);
}
