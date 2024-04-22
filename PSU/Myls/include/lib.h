/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** lib.h
*/

#ifndef _LIB_H
    #define _LIB_H

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
void my_sort_char_array(char **array);
void my_reverse_str(char **array);

#endif /* !_LIB_H */
