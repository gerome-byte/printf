#include"main.h"

/**
 * _printf - prints output to the standard output
 * @format: format of our string.
 * Return: number of charcters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0;
	char *k;

	unsigned int b = 0;

	va_list(ap);


	va_start(ap, format);

	while (i < strlen(format))
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			i++;
		}
		else
		{
			if (format[i + 1] == 'c')
			{
				putchar(va_arg(ap, int));
				i =+ 2;
			}
			else if (format[i + 1] == 's')
			{
				k = (va_arg(ap, char *));

				while (b < strlen(k))
				{
					putchar(k[b]);
					b++;
				}
				i =+ 2;
			}
			else
			{
				putchar(format[i]);
				i++;
			}
		}
	}
	va_end(ap);
	return (i + b);
}
