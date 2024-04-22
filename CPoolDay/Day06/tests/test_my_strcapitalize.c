/*
** EPITECH PROJECT, 2022
** test strcapitalize
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, my_strcapitalize_a) {
    char s1[] = "hey, how are You?";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Hey, How Are You?");
}

Test(my_strcapitalize, my_strcapitalize_b) {
    char s1[] = "42WORds forty-two; fifty+one";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "42words Forty-Two; Fifty+One");
}

Test(my_strcapitalize, my_strcapitalize_c) {
    char s1[] = "i lIkE iT";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "I Like It");
}

Test(my_strcapitalize, my_strcapitalize_d) {
    char s1[] = "quaTorZe+Vingt-SePt";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Quatorze+Vingt-Sept");
}

Test(my_strcapitalize, my_strcapitalize_e) {
    char s1[] = "quaTorZe+Vi~gt-SePt";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Quatorze+Vi~gt-Sept");
}

Test(my_strcapitalize, my_strcapitalize_f) {
    char s1[] = "quaTorZe+Vingt-S_Pt";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Quatorze+Vingt-S_pt");
}

Test(my_strcapitalize, my_strcapitalize_g) {
    char s1[] = "quaTorZe+Vingt-@sPt";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Quatorze+Vingt-@Spt");
}

Test(my_strcapitalize, my_strcapitalize_h) {
    char s1[] = "quaTorZe+Vingt-[sPt";
    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Quatorze+Vingt-[Spt");
}
