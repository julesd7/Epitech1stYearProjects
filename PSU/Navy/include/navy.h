/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy.h
*/

#ifndef _NAVY_H
    #define _NAVY_H

    #include <signal.h>

    #include "lib.h"

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define OPEN_ERROR -1
    #define READ_ERROR 0
    #define NOT_CONNECTED -16
    #define ONE_SEC 1000000

    typedef struct navy {
        char **my_map;
        char **enemy_map;
        char *buffer;
        int is_host;
        int size;
        int pid;
        int fd;
        int rd;
    }navy_t;

    typedef struct boat {
        int size;
        int start_row;
        int start_col;
        int end_row;
        int end_col;
        int row;
        int col;
    }boat_t;

int is_loose(void);
int is_win(void);
int check_victory(char **map);

int start_client(navy_t *navy, char *get_host_pid);

int open_pos(navy_t *navy, char *filepath);

void fill_boat(navy_t *navy, boat_t boat);

int check_error(navy_t *navy, char *buf);
int handle(navy_t *navy, int ac, char **av);


struct sigaction *init_sigaction(void (*hand)(int, siginfo_t *, void *));

int start_navy(navy_t *navy, char *host_pid);

void signo_update(int signum, siginfo_t *siginfo, void *ptr);
int send_shoot(char *shoot, int pid);
int send_paquet(int pid, navy_t *navy);
int get_shoot(int pid);
int get_paquet(int pid, navy_t *navy);

void print_map(navy_t *navy);

int start_server(navy_t *navy);

void is_my_missed(navy_t *navy, char row, char col);
void is_my_hit(navy_t *navy, char row, char col);
void is_he_missed(navy_t *navy, int pos);
void is_he_hit(navy_t *navy, int pos);

#endif /* !_NAVY_H */
