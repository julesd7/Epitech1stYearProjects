/*
** EPITECH PROJECT, 2022
** test my strncmp
** File description:
** tests
*/

#include <criterion/criterion.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, my_strncmp_greater) {
    char s1[] = "Hello";
    char s2[] = "Hell";
    int verif = my_strncmp(s1, s2, 6);
    cr_assert_eq(verif, 1);
}

Test(my_strncmp, my_strncmp_lower) {
    char s1[] = "Hell";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 6);
    cr_assert_eq(verif, -1);
}

Test(my_strncmp, my_strncmp_egals) {
    char s1[] = "Hello";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 6);
    cr_assert_eq(verif, 0);
}

Test(my_strncmp, my_strncmp_egals_withN) {
    char s1[] = "Hello";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 3);
    cr_assert_eq(verif, 0);
}

Test(my_strncmp, my_strncmp_egals_withBigN) {
    char s1[] = "Hello";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 12);
    cr_assert_eq(verif, 0);
}

Test(my_strncmp, my_strncmp_egals_withBigN_andS2) {
    char s1[] = "Hello";
    char s2[] = "Hellooooooooooo";
    int verif = my_strncmp(s1, s2, 16);
    cr_assert_eq(verif, -1);
}

Test(my_strncmp, my_strncmp_egals_withBigN_andS1) {
    char s1[] = "Hellooooooooooo";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 16);
    cr_assert_eq(verif, 1);
}

Test(my_strncmp, my_strncmp_egals_withN2) {
    char s1[] = "Helloas";
    char s2[] = "Hello";
    int verif = my_strncmp(s1, s2, 5);
    cr_assert_eq(verif, 0);
}
