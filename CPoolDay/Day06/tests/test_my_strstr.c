/*
** EPITECH PROJECT, 2022
** test strstr
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, strstr) {
    char a[] = "helloWorld";
    char b[] = "lo";
    char *str = my_strstr(a, b);
    cr_assert_str_eq(str, "loWorld");
}

Test(my_strstr, strstr3) {
    char a[] = "";
    char b[] = "lo";
    char *str = my_strstr(a, b);
    cr_assert_eq(str, NULL);
}
