#include "../include/so_long_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}