#include "ft_printf.h"

int	ft_puthex(unsigned long nb)
{
	int		counter;
	char	*tab_hex;

	counter = 0;
	tab_hex = "0123456789abcdef";
	if (nb > 15)
		counter = counter + ft_puthex(nb / 16);
	write(1, &tab_hex[nb % 16], 1);
	counter++;
	return (counter);
}

int	ft_puthex_up(unsigned long nb)
{
	int		counter;
	char	*tab_hex;

	counter = 0;
	tab_hex = "0123456789ABCDEF";
	if (nb > 15)
		counter = counter + ft_puthex_up(nb / 16);
	write(1, &tab_hex[nb % 16], 1);
	counter++;
	return (counter);
}

int	ft_puthex_ptr(void *nb)
{
	int				counter;
	unsigned long	nb_conv;

	counter = 0;
	nb_conv = (unsigned long)nb;
	if (nb_conv == 0)
	{
		ft_putstr("0x0");
		return (3);
	}
	ft_putstr("0x");
	counter += 2;
	counter = counter + ft_puthex(nb_conv);
	return (counter);
}