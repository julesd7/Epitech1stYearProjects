/*
** EPITECH PROJECT, 2022
** my evil str
** File description:
** swap one-one, the first letter is the last one of the word
*/

char *my_evil_str(char *str)
{
    int sv = my_strlen(str) - 1;
    char wait;
    for (int t = 0; t < sv; t++) {
        wait = str[t];
        str[t] = str[sv];
        str[sv] = wait;
        sv--;
    }
    return (str);
}
