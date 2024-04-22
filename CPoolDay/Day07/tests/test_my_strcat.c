/*
** EPITECH PROJECT, 2022
** test strcat
** File description:
** tests
*/

#include <criterion/criterion.h>

char *my_strcat(char *dest, char const *src);

Test(my_strcat, my_strcat_a) {
    char dest[] = "Hey, ";
    my_strcat(dest, "how are you ?");
    cr_assert_str_eq(dest, "Hey, how are you ?");
}
