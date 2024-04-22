/*
** EPITECH PROJECT, 2023
** navy
** File description:
** server
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "navy.h"

static sig_atomic_t signo;

static void server(int check_sig, siginfo_t *siginfo, void *ptr)
{
    if (check_sig == SIGUSR2)
        signo = siginfo->si_pid;
}

static int server_loop(int pid, navy_t *navy)
{
    init_sigaction(signo_update);
    print_map(navy);

    while (1) {
        send_paquet(pid, navy);
        if (check_victory(navy->my_map) == 1)
            return is_loose();
        get_paquet(pid, navy);
        if (check_victory(navy->enemy_map) == 1)
            return is_win();
        print_map(navy);
    }
}

int start_server(navy_t *navy)
{
    signo = NOT_CONNECTED;
    if (init_sigaction(server) == NULL)
        return EXIT_FAIL;
    my_putstr("waiting for enemy connection...\n\n");
    usleep(10 * ONE_SEC);
    if (signo == NOT_CONNECTED) {
        my_putstr("Timeout\n");
        return EXIT_FAIL;
    }
    kill(signo, SIGUSR2);
    my_putstr("enemy connected\n\n");
    return server_loop(signo, navy);
}
