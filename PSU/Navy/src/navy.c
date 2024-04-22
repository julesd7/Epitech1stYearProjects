/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy.c
*/

#include "navy.h"

int start_navy(navy_t *navy, char *host_pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(navy->pid);
    my_putchar('\n');
    if (navy->is_host)
        return start_server(navy);
    else
        return start_client(navy, host_pid);
}
