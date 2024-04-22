/*
** EPITECH PROJECT, 2023
** navy
** File description:
** init_signation.c
*/

#include <stdlib.h>
#include <stddef.h>

#include "navy.h"

struct sigaction *init_sigaction(void (*hand)(int, siginfo_t *, void *))
{
    struct sigaction *sig = malloc(sizeof(struct sigaction) * 1);

    (*sig).sa_sigaction = hand;
    sigemptyset(&(sig->sa_mask));
    (*sig).sa_flags = SA_RESTART;
    (*sig).sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, sig, NULL) == OPEN_ERROR ||
    sigaction(SIGUSR2, sig, NULL) == OPEN_ERROR)
        return NULL;
    return sig;
}
