/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** use_semicolons
*/

#include <stdlib.h>

#include "mysh.h"

static void create_cmd(mysh_t *mysh, check_t *check, char **cmd, int *infos)
{
    char *temp = NULL;
    char **cmd_temp = NULL;

    temp = malloc(sizeof(char) * (infos[1] + 1));
    temp[0] = '\0';
    for (int i = infos[0]; cmd[i] != NULL ; i++) {
        if (my_strcmp(cmd[i], ";") == 0)
            break;
        my_strcat(temp, cmd[i]);
        my_strcat(temp, ";");
    }
    cmd_temp = my_strtowarray(temp, ';');
    use_command(mysh, check, cmd_temp);
    free(temp);
    free_array(cmd_temp);
}

static int loop_semi(mysh_t *mysh, check_t *check, char **cmd, int end)
{
    int infos[2];

    for (int i = 0; i < end; i++) {
        infos[0] = i;
        infos[1] = 0;
        for (int j = i; cmd[j] != NULL && my_strcmp(cmd[j], ";") != 0; j++) {
            infos[1] += my_strlen(cmd[j]);
            infos[1] ++;
            i++;
        }
        create_cmd(mysh, check, cmd, infos);
    }
}

void use_semicolons(mysh_t *mysh, check_t *check, char **cmd)
{
    int end = 0;

    for (int i = 0; cmd[i] != NULL; i++)
        end ++;

    loop_semi(mysh, check, cmd, end);
}
