/*
** EPITECH PROJECT, 2022
** test my_strupcase
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strupcase(char *str);

Test(my_strupcase, my_strupcase_a) {
    char s1[] = "HellOWoRld";
    my_strupcase(s1);
    cr_assert_str_eq(s1, "HELLOWORLD");
}

Test(my_strupcase, my_strupcase_b) {
    char s1[] = "HellOWoRld";
    cr_assert_eq(my_strupcase(s1), s1);
}

Test(my_strupcase, my_strupcase_c) {
    char s1[] = "HellOW494d";
    my_strupcase(s1);
    cr_assert_str_eq(s1, "HELLOW494D");
}

Test(my_strupcase, my_strupcase_d) {
    char s1[] = "HellOW~d";
    my_strupcase(s1);
    cr_assert_str_eq(s1, "HELLOW~D");
}
