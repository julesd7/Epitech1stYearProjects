/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** lib h
*/

#ifndef _LIB_H
    #define _LIB_H

    char *my_strcat(char *dest, char const *src);
    int my_strlen(char const *str);
    int my_putstr(char const *str);
    void my_putchar(char c);
    char **my_strtowarray(char const *str, const char separator);
    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_str_is_alpha(char const *str);
    int my_is_printable(char const c);
    int my_atoi(const char *str);

#endif /* !_LIB_H */
