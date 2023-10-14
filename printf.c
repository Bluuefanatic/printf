#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - A custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;

            switch (*format)
            {
                case 'c':
                    {
                        char ch = (char)va_arg(args, int);
                        count += write(1, &ch, 1);
                    }
                    break;

                case 's':
                    count += write(1, va_arg(args, char*), 1);
                    break;

                case '%':
                    count += write(1, "%", 1);
                    break;

                default:
                    count += write(1, "%", 1);
                    count += write(1, format, 1);
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}
