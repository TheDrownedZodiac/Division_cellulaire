/*
 * E89 Pedagogical & Technical Lab
 * project:     day204
 * created on:  2023-04-06 - 15:40 +0200
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: pipe command test
 */

#include "fonction.h"

int main(void)
{
    const char *cmd[2] = {"echo Luffy", "wc -c"};

    pipe_commands(cmd);
    return 0;
}
