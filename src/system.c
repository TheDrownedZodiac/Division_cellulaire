/*
 * E89 Pedagogical & Technical Lab
 * project:     day4
 * created on:  2023-02-08 - 10:13 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: systeme
 */

#include "fonction.h"

int stu_system(const char *cmd)
{
    pid_t wrong;
    pid_t fork_res;
    int wstatus;

    fork_res = fork();
    if (fork_res == -1) {
        return -1;
    }
    if (fork_res == 0) {
        execl("/bin/sh", "sh", "-c", cmd, (char *) NULL);
        return 0;
    }
    wrong = waitpid(0, &wstatus, 0);
    if (wrong < 0) {
        return EXIT_FAILURE;
    }
    while (!WIFEXITED(wstatus)) {
        return WIFEXITED(wstatus);
    }
    return 0;
}
