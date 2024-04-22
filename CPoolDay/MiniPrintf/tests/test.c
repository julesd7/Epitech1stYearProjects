/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** Tests for mini_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int mini_printf(const char *format, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mini_printf, verify_return, .init = redirect_all_std)
{
    int size = mini_printf("%d %i %s %c%c", 48, 12, "48", '1', '2');
    cr_assert_eq(size, 11);
}

Test(mini_printf, unknown_flags, .init = redirect_all_std)
{
    mini_printf("%w", 17);
    cr_assert_stdout_eq_str("%");
}

Test(mini_printf, simple_testing_string, .init = redirect_all_std)
{
    mini_printf("Im Here for Test");
    cr_assert_stdout_eq_str("Im Here for Test");
}

Test(mini_printf, use_double_string, .init = redirect_all_std)
{
    mini_printf("%s %s", "here", "for testing");
    cr_assert_stdout_eq_str("here for testing");
}

Test(mini_printf, all_flags, .init = redirect_all_std)
{
    mini_printf("%d %i %s %c%c", 42, 42, "42", '4', '2');
    cr_assert_stdout_eq_str("42 42 42 42");
}

Test(mini_printf, str_with_percentage, .init = redirect_all_std)
{
    mini_printf("Hello %s", "World");
    cr_assert_stdout_eq_str("Hello World");
}

Test(mini_printf, print_int, .init = redirect_all_std)
{
    mini_printf("Hello World %d", 4864);
    cr_assert_stdout_eq_str("Hello World 4864");
}

Test(mini_printf, character_testing, .init = redirect_all_std)
{
    mini_printf("Hello World %c", 'W');
    cr_assert_stdout_eq_str("Hello World W");
}

Test(mini_printf, calc_and_int, .init = redirect_all_std)
{
    mini_printf("%d * %d = %i", 92, 48, 92 * 48);
    cr_assert_stdout_eq_str("92 * 48 = 4416");
}

Test(mini_printf, double_percentage, .init = redirect_all_std)
{
    mini_printf("%% Hello World %%");
    cr_assert_stdout_eq_str("% Hello World %");
}

Test(mini_printf, a_lot_of_char, .init = redirect_all_std)
{
    mini_printf("%c%c%c%c%c%c%c%c%c%c%c", 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd');
    cr_assert_stdout_eq_str("Hello World");
}
