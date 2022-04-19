#include "main.h"

/**
 * _vprintf_state_1 - prints string and argument when state == 1
 * @format: string to print
 * @args: list of arguments to print
 * Return: nothing
 */
void _vprintf_state_1(const char *format, va_list args)
{
	int i;
	void *p;
	const char *s;
	char num_buf[65];

	switch (*format)
	{
		case 'c':
			putchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, const char *);
			while (*s)
				putchar(*s++);
			break;
		case 'i':
		case 'd':
			putchar_int(va_arg(args, int));
			break;
		case 'u':
			print_unsigned(va_arg(args, int), 10, num_buf, 0);
			break;
		case 'x':
			print_unsigned(va_arg(args, int), 16, num_buf, 0);
			break;
		case 'X':
			print_unsigned(va_arg(args, int), 16, num_buf, 1);
			break;
		case 'o':
			print_unsigned(va_arg(args, int), 8, num_buf, 0);
			break;
		case 'p':
			putchar('0');
			putchar('x');
			p = va_arg(args, void *);
			putchar_num((uint64_t) p, 16, num_buf, 0);
			for (i = 0; num_buf[i]; i++)
				putchar(num_buf[i]);
			break;
		case '%':
			putchar('%');
			break;
		default:
			putchar('%');
			putchar(*format);
	}
}
