
/*
** EPITECH PROJECT, 2022
** test cat
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

int read_it(int ac, char **av);

void setup(void)
{
    cr_redirect_stdout();
}

void setuperr(void)
{
    cr_redirect_stderr();
}

Test(test, cat_error_b, .init=setuperr) {
    char *av[] = {"a.out", "./units/hello.c", 0};
    read_it(2 , av);
    cr_assert_stderr_eq_str("cat: ./units/hello.c: No such file or directory\n");
}

Test(test, cat_error_c, .init=setuperr) {
    char *av[] = {"a.out", "./units/directory/", 0};
    read_it(2 , av);
    cr_assert_stderr_eq_str("cat: ./units/directory/: Is a directory\n");
}

Test(test, cat_error_d, .init=setuperr) {
    char *av[] = {"a.out", ".", 0};
    read_it(2 , av);
    cr_assert_stderr_eq_str("cat: .: Is a directory\n");
}

Test(test, cat_error_e, .init=setup) {
    char *av[] = {"./a.out", "./units/text.txt", 0};
    read_it(2 , av);
    cr_assert_stdout_eq_str("helllo\n");
}
