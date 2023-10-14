#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            int num = va_arg(args, int);
            char buffer[12];  /* Maximum size for a 32-bit integer */

            int len = snprintf(buffer, sizeof(buffer), "%d", num);
            count += write(1, buffer, len);

            format++;
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
