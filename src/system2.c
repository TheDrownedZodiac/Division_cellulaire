/*
 * E89 Pedagogical & Technical Lab
 * project:     day4
 * created on:  2023-02-09 - 10:59 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: system2
 */

#include "fonction.h"

pid_t g_child;

static void handler(int sign)
{
    if (sign == SIGINT) {
        kill(g_child, SIGINT);
    }
}

static int def_fork(pid_t fork_res, const char *cmd)
{
    if (fork_res == -1) {
        return -1;
    }
    if (fork_res == 0) {
        execl("/bin/sh", "sh", "-c", cmd, NULL);
        return 0;
    }
    return 0;
}

int stu_system2(const char *cmd)
{
    pid_t wrong;
    pid_t fork_res;
    int wstatus;
    struct sigaction sa;

    fork_res = fork();
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    def_fork(fork_res, cmd);
    g_child = fork_res;
    sigaction(SIGINT, &sa, NULL);
    wrong = waitpid(0, &wstatus, 0);
    sa.sa_handler = 0;
    sa.sa_flags = SA_RESETHAND;
    write(1, "\nKill", 6);
    if (wrong < 0) {
        return EXIT_FAILURE;
    }
    while (!WIFEXITED(wstatus)) {
        return WIFEXITED(wstatus);
    }
    return 0;
}
