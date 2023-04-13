/*
 * E89 Pedagogical & Technical Lab
 * project:     fonction
 * created on:  2023-02-06 - 17:03 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: fonction
 */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <signal.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <lapin.h>
#include <sys/wait.h>
#include "struct.h"

#ifndef STU_H_

#define STU_H_

int to_each_their_turn(char *str);
int stu_strlen(const char *str);
int stu_system(const char *cmd);
int stu_system2(const char *cmd);
int stuborn(void);
int pipe_commands(const char **commands);

#endif
