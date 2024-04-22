/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** option_l.c
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my_ls.h"

static void last_mod(char *str)
{
    int size = my_strlen(str);

    for (int i = 4; i < size - 9; i++)
        my_putchar(str[i]);
}

static void get_perms(struct stat file_stat)
{
    if (!(file_stat.st_mode & S_IWUSR) && !(file_stat.st_mode & S_IXUSR))
        my_putchar('-');
    else {
    my_putchar((file_stat.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((file_stat.st_mode & S_IXUSR) ? 'x' : '-');
    }
    my_putchar((file_stat.st_mode & S_IRGRP) ? 'r' : '-');
    if (!(file_stat.st_mode & S_IWGRP) && !(file_stat.st_mode & S_IXGRP))
        my_putchar('-');
    else {
    my_putchar((file_stat.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((file_stat.st_mode & S_IXGRP) ? 'x' : '-');
    }
    my_putchar((file_stat.st_mode & S_IROTH) ? 'r' : '-');
    if (!(file_stat.st_mode & S_IWOTH) && !(file_stat.st_mode & S_IXOTH))
        my_putchar('-');
    else {
    my_putchar((file_stat.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((file_stat.st_mode & S_IXOTH) ? 'x' : '-');
    }
}

static int get_total_block(char **buffer, char verif,\
struct stat file_stat, char *filepath)
{
    char temp[500][500];
    int total = 0;
    for (int i = 0; buffer[i] != NULL; i++) {
        my_strcat(temp[i], "./");
        my_strcat(temp[i], filepath);
        my_strcat(temp[i], "/");
        my_strcat(temp[i], buffer[i]);
        verif = buffer[i][0];
        if (verif != '.') {
            stat(temp[i], &file_stat);
            total += file_stat.st_blocks;
        }
    }
    return (total / 2);
}

static void print_l(struct stat file_stat)
{
    my_putchar((S_ISDIR(file_stat.st_mode)) ? 'd' : '-');
    my_putchar((file_stat.st_mode & S_IRUSR) ? 'r' : '-');
    get_perms(file_stat);
    my_putchar(' ');
    my_put_nbr(file_stat.st_nlink);
    my_putchar(' ');
    my_putstr(getpwuid(file_stat.st_uid)->pw_name);
    my_putchar(' ');
    my_putstr(getgrgid(file_stat.st_gid)->gr_name);
    my_putchar(' ');
    my_put_nbr(file_stat.st_size);
    my_putchar(' ');
    last_mod(ctime(&file_stat.st_ctime));
    my_putchar(' ');

}

int use_option_l(options_t options, char **buffer, char *files)
{
    struct stat file_stat;
    char verif = ' ';
    char filepath[500][500];
    my_putstr("total ");
    my_put_nbr(get_total_block(buffer, verif, file_stat, files));
    my_putchar('\n');
    for (int i = 0; buffer[i] != NULL; i++) {
        my_strcat(filepath[i], "./");
        my_strcat(filepath[i], files);
        my_strcat(filepath[i], "/");
        my_strcat(filepath[i], buffer[i]);
        if (options.opt_a == 0)
            verif = buffer[i][0];
        if (verif != '.') {
            stat(filepath[i], &file_stat);
            print_l(file_stat);
            my_putstr(buffer[i]);
            my_putchar('\n');
        }
    }
}
