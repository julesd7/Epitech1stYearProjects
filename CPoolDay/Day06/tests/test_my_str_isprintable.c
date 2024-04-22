/*
** EPITECH PROJECT, 2022
** test my str is printable
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_str_isprintable(char const *str);

Test (my_str_isprintable, test_a) {
    char sent[] = "hello";
    sent[0] = 24;
    int verif = my_str_isprintable(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isprintable, test_b) {
    char sent[] = "hello";
    sent[0] = 127;
    int verif = my_str_isprintable(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isprintable, test_c) {
    char sent[] = "";
    int verif = my_str_isprintable(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isprintable, test_d) {
    char sent[] = "hello";
    sent[0] = 58;
    int verif = my_str_isprintable(sent);
    cr_assert_eq(verif, 1);
}
