#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_sayi_len(long sayi);
int	ft_putnbr(int nbr);
int	ft_format(char format, va_list argv);
int	ft_printf(const char *str, ...);
int	hex_base(unsigned long num, char x, int i);

#endif
