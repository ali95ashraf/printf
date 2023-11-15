//
// Created by Ali Ashraf on 13/11/2023.
//
#include "main.h"
/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: void
*/
int _puts(char *str)
{
    char *a = str;

    while (*str)
        _putchar (*str++);
    return (str - a);
}
/*
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(int c) {
    static int i = 0;
    static char buf[OUTPUT_BUF_SIZE] = {0};

    if (i == OUTPUT_BUF_SIZE || c == BUF_FLUSH) {
        write(1, buf, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
        buf[i++] = c;

    return 1;
}