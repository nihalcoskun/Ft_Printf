#include "ft_printf.h"
/*  ****differences between %d and %i
    there is no differences between %d and %i 
	in printf but %d and %i behavior is different in scanf
    %i auto detects the base of the number and 
	convert it to the decimal && %d assume base 10.
    012(octal) -> %i -> 10
    012(octal) -> %d -> 12
*/

int	ft_format(char format, va_list argv)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_putchar(va_arg(argv, int));
	else if (format == 's')
		result += ft_putstr(va_arg(argv, char *));
	else if (format == 'd' || format == 'i')
		result += ft_putnbr(va_arg(argv, int));
	else if (format == 'u')
		result += hex_base(va_arg(argv, unsigned int), 'x', 10);
	else if (format == 'p')
	{
		result += write(1, "0x", 2);
		result += hex_base(va_arg(argv, unsigned long), 'p', 16);
	}
	else if (format == 'x' || format == 'X')
		result += hex_base(va_arg(argv, unsigned int), format, 16);
	else if (format == '%')
		return (ft_putchar('%'));
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		toplam_karakter_sy;

	va_start(list, str);
	toplam_karakter_sy = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			toplam_karakter_sy += ft_format(*(str + 1), list);
			str++;
		}
		else
		{
			write(1, str, 1);
			toplam_karakter_sy++;
		}
		str++;
	}
	va_end (list);
	return (toplam_karakter_sy);
}

int main(void)
{
    ft_printf("alinin ilk harfi %c'dir. ", 'a');
    return (0);
} 
