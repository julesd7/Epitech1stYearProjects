/*
** EPITECH PROJECT, 2023
** dante/solver
** File description:
** solver.h
*/

#ifndef _SOLVER_H
    #define _SOLVER_H

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define IMPOSSIBLE 'N'

    #include <stdbool.h>

    bool is_error(int ac, char **av);
    int solver(char *path);
    char *process(char *maze);


#endif /* !_SOLVER_H */
