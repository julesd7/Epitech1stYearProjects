/*
** EPITECH PROJECT, 2023
** navy
** File description:
** paquets.c
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "navy.h"

static sig_atomic_t signo;

void signo_update(int signum, siginfo_t *siginfo, void *ptr)
{
    if (signum == SIGUSR2)
        signo = 1;
    else
        signo = 0;
}

int send_shoot(char *shoot, int pid)
{
    int col = (shoot[0] - 'A');
    int row = (shoot[1] - '0');

    for (int i = 2; i >= 0; i--) {
        signo = 0;
        kill(pid, SIGUSR1 + (((col >> i) & 1) * 2));
        pause();
        usleep(0.01 * ONE_SEC);
    }
    for (int i = 2; i >= 0; i--) {
        signo = 0;
        kill(pid, SIGUSR1 + ((row >> i) & 1) * 2);
        pause();
        usleep(0.01 * ONE_SEC);
    }
    return EXIT_SUCCESS;
}

int send_paquet(int pid, navy_t *navy)
{
    char buf[3] = "";

    my_putstr("attack: ");
    usleep(ONE_SEC);
    read(0, buf, 2);
    buf[2] = '\0';
    if (check_error(navy, buf) == 84) {
        my_putstr("wrong position\n");
        return send_paquet(pid, navy);
    }
    navy->enemy_map[buf[1] - '0'][(buf[0] - 'A') * 2] = 'x';
    usleep(ONE_SEC);
    send_shoot(buf, pid);
    pause();
    if (signo == 0)
        is_my_missed(navy, buf[1], buf[0]);
    else
        is_my_hit(navy, buf[1], buf[0]);
    return EXIT_SUCCESS;
}

int get_shoot(int pid)
{
    int col = 0;
    int row = 0;

    for (int i = 0; i < 3; i++) {
        pause();
        usleep(0.01 * ONE_SEC);
        col = col * 2 + (int)signo;
        kill(pid, SIGUSR2);
    }
    for (int i = 0; i < 3; i++) {
        pause();
        usleep(0.01 * ONE_SEC);
        row = row * 2 + (int)signo;
        kill(pid, SIGUSR2);
    }
    return (col * 10 + row);
}

int get_paquet(int pid, navy_t *navy)
{
    char is_hit = 0;
    int shoot = 0;

    my_putstr("waiting for enemy's attack\n");
    shoot = get_shoot(pid);
    is_hit = navy->my_map[shoot % 10][shoot / 10 * 2];
    usleep(ONE_SEC);
    if (is_hit == '.') {
        is_he_missed(navy, shoot);
        kill(pid, SIGUSR1);
    } else {
        is_he_hit(navy, shoot);
        kill(pid, SIGUSR2);
    }
    return EXIT_SUCCESS;
}
