/*
 * E89 Pedagogical & Technical Lab
 * project:     tp variadique
 * created on:  2022-11-29 - 14:06 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: strlen
 */

int stu_strlen(const char *str)
{
    unsigned int count;

    count = 0;
    while (str[count] != '\0') {
        count += 1;
    }
    return count;
}
