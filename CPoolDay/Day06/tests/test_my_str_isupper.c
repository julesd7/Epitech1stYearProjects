/*
** EPITECH PROJECT, 2022
** test my str is upper
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_str_isupper(char const *str);

Test (my_str_isupper, test_a) {
    char sent[] = "";
    int verif = my_str_isupper(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isupper, test_b) {
    char sent[] = "HELLO";
    int verif = my_str_isupper(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isupper, test_c) {
    char sent[] = "HelLO";
    int verif = my_str_isupper(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isupper, test_d) {
    char sent[] = "HEL9O";
    int verif = my_str_isupper(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isupper, test_e) {
    char sent[] = "H5L@O";
    int verif = my_str_isupper(sent);
    cr_assert_eq(verif, 0);
}
