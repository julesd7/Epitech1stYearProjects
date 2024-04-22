/*
** EPITECH PROJECT, 2022
** test my strlowcase
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strlowcase(char *str);

Test(my_strlowcase, my_strlowcase_a) {
    char s1[] = "HellOWoRld";
    my_strlowcase(s1);
    cr_assert_str_eq(s1, "helloworld");
}

Test(my_strlowcase, my_strlowcase_b) {
    char s1[] = "HellOWoRld";
    cr_assert_eq(my_strlowcase(s1), s1);
}

Test(my_strlowcase, my_strlowcase_c) {
    char s1[] = "HellOW494d";
    my_strlowcase(s1);
    cr_assert_str_eq(s1, "hellow494d");
}

Test(my_strlowcase, my_strlowcase_d) {
    char s1[] = "HellOW~d";
    my_strlowcase(s1);
    cr_assert_str_eq(s1, "hellow~d");
}
