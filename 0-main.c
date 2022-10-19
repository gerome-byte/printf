#include"main.h"

/**
 * _printf - prints output to the standard output
 * @format: format of our string.
 * Return: number of charcters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	char *k;

	unsigned int b = 0;

	va_list(ap);


	va_start(ap, format);

	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] != '%')
			putchar(format[i]);
		else
		{
			if (format[i + 1] == 'c')
			{
				putchar(va_arg(ap, int));
				i++;
			}
			else if (format[i + 1] == 's')
			{
				k = (va_arg(ap, char *));

				while (b < strlen(k))
				{
					putchar(k[b]);
					b++;
				}
				++i;
			}
			else
				putchar(format[i]);
		}
	}
	va_end(ap);
	return (i + b);
}

/**
 * main - runs print function
 * Return: 0
 */

int main(void)
{
	char *s = "gabriel";
	char c = 'C';

	_printf("i am %d and i like %c\n", s, c);
	return (0);
}
