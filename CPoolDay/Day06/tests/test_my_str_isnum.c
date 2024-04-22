/*
** EPITECH PROJECT, 2022
** test my str isnum
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_str_isnum(char const *str);

Test (my_str_isnum, test_a) {
    char sent[] = "";
    int verif = my_str_isnum(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isnum, test_b) {
    char sent[] = "10246589";
    int verif = my_str_isnum(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isnum, test_c) {
    char sent[] = "5";
    int verif = my_str_isnum(sent);
    cr_assert_eq(verif, 1);
}

Test (my_str_isnum, test_d) {
    char sent[] = "012ad5";
    int verif = my_str_isnum(sent);
    cr_assert_eq(verif, 0);
}

Test (my_str_isnum, test_e) {
    char sent[] = "5#sc4";
    int verif = my_str_isnum(sent);
    cr_assert_eq(verif, 0);
}
