#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Character string containing directives.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    int num, temp, len;
    char buffer[11];
    int i;
    char ch;
    char *str;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    ch = (char) va_arg(args, int);
                    write(1, &ch, 1);
                    printed_chars++;
                    break;

                case 's':
                    str = va_arg(args, char *);
                    while (*str)
                    {
                        write(1, str, 1);
                        str++;
                        printed_chars++;
                    }
                    break;

                case 'd':
                case 'i':
                    num = va_arg(args, int);
                    len = 0;
                    if (num < 0)
                    {
                        write(1, "-", 1);
                        printed_chars++;
                        num *= -1;
                    }
                    temp = num;
                    do {
                        temp /= 10;
                        len++;
                    } while (temp != 0);
                    for (i = len - 1; i >= 0; i--)
                    {
                        buffer[i] = (num % 10) + '0';
                        num /= 10;
                    }
                    write(1, buffer, len);
                    printed_chars += len;
                    break;

                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;

                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
