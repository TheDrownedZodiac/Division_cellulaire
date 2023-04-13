/*
 * E89 Pedagogical & Technical Lab
 * project:     to_each_theri_turn
 * created on:  2023-02-07 - 16:41 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: to_each_their_turn
 */

#include "fonction.h"

int to_each_their_turn(char *str)
{
    pid_t wrong;
    pid_t fork_res;
    int wstatus;

    fork_res = fork();
    if (fork_res == -1) {
        return -1;
    }
    if (fork_res == 0) {
        write(1, "child:", 6);
        write(1, str, stu_strlen(str));
        write(1, "\n", 1);
        return 0;
    }
    wrong = waitpid(fork_res, &wstatus, 0);
    if (wrong < 0) {
        return EXIT_FAILURE;
    }
    write(1, "parent:", 7);
    write(1, str, stu_strlen(str));
    write(1, "\n", 1);
    while (!WIFEXITED(wstatus)) {
        return WIFEXITED(wstatus);
    }
    return 0;
}
