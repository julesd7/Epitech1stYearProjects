/*
** EPITECH PROJECT, 2022
** test my str islower
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_str_islower(char const *str);

Test (my_str_islower, test_a) {
    char sent[] = "";
    int verif = my_str_islower(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_islower, test_b) {
    char sent[] = "hello";
    int verif = my_str_islower(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_islower, test_c) {
    char sent[] = "HELLO";
    int verif = my_str_islower(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_islower, test_d) {
    char sent[] = "hello{";
    int verif = my_str_islower(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_islower, test_e) {
    char sent[] = "hel0O";
    int verif = my_str_islower(sent);
    cr_assert_eq(verif, 0);
}
