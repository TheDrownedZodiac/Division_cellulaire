/*
 * E89 Pedagogical & Technical Lab
 * project:     day204
 * created on:  2023-04-06 - 15:40 +0200
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: pipe command
 */

#include "fonction.h"

static void childe(int *pipefd, int nb_1, int nb_2, const char *cmd)
{
        close(pipefd[nb_1]);
        dup2(pipefd[nb_2], nb_2);
        close(pipefd[nb_2]);
        execl("/bin/sh", "sh", "-c", cmd, (char *) NULL);
}

static int exit_(pid_t fork_1, pid_t fork_2, int *pipefd)
{
    int wstatus;

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(fork_1, &wstatus, 0);
    while (!WIFEXITED(wstatus)) {
        return WIFEXITED(wstatus);
    }
    waitpid(fork_2, &wstatus, 0);
    while (!WIFEXITED(wstatus)) {
        return WIFEXITED(wstatus);
    }
    return 0;
}

int pipe_commands(const char **commands)
{
    pid_t fork_1;
    pid_t fork_2;
    int pipefd[2];

    pipe(pipefd);
    fork_1 = fork();
    if (fork_1 == -1) {
        return -1;
    }
    if (fork_1 == 0) {
        childe(pipefd, 0, 1, commands[0]);
    }
    fork_2 = fork();
    if (fork_2 == -1) {
        return -1;
    }
    if (fork_2 == 0) {
        childe(pipefd, 1, 0, commands[1]);
    }
    return exit_(fork_1, fork_2, pipefd);
}
