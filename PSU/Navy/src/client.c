/*
** EPITECH PROJECT, 2023
** navy
** File description:
** client
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "navy.h"

static sig_atomic_t signo;

static void client(int check_sig, siginfo_t *siginfo, void *ptr)
{
    if (check_sig == SIGUSR2 && siginfo->si_pid == signo)
        signo = 1;
}

static int client_loop(int pid, navy_t *navy)
{
    init_sigaction(signo_update);
    print_map(navy);

    while (1) {
        get_paquet(pid, navy);
        if (check_victory(navy->my_map) == 1)
            return is_loose();
        send_paquet(pid, navy);
        if (check_victory(navy->enemy_map) == 1)
            return is_win();
        print_map(navy);
    }
}

int start_client(navy_t *navy, char *get_host_pid)
{
    int host_pid = my_getnbr(get_host_pid);
    signo = host_pid;

    if (init_sigaction(client) == NULL)
        return EXIT_FAIL;
    kill(host_pid, SIGUSR2);
    usleep(2 * ONE_SEC);
    if (signo != 1) {
        my_putstr("Timeout\n");
        return EXIT_FAIL;
    }
    my_putstr("successfully connected\n\n");
    return client_loop(host_pid, navy);
}
