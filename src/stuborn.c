/*
 * E89 Pedagogical & Technical Lab
 * project:     day4
 * created on:  2023-02-09 - 09:26 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: stuborn
 */

#include "fonction.h"

static void handler(int sa)
{
    if (sa == SIGINT) {
        write(1, "\nCa marche bien", 15);
    }
}

int stuborn(void)
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);
    sleep(10);
    sleep(10);
    return 0;
}
