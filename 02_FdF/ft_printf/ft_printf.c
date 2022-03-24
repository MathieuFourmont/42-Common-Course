/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:48:18 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/30 09:51:13 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(va_list *args, const char *format, int i, int *counter)
{
	if (format[i] == 'c')
		*counter = *counter + ft_putchar(va_arg(*args, int));
	else if (format[i] == 's')
		*counter = *counter + ft_putstr(va_arg(*args, char *));
	else if (format[i] == 'p')
		*counter = *counter + ft_puthex_ptr(va_arg(*args, void *));
	else if (format[i] == 'd' || format[i] == 'i')
		*counter = *counter + ft_putnbr(va_arg(*args, int));
	else if (format[i] == 'u')
		*counter = *counter + ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (format[i] == 'x')
		*counter = *counter + ft_puthex(va_arg(*args, unsigned int));
	else if (format[i] == 'X')
		*counter = *counter + ft_puthex_up(va_arg(*args, unsigned int));
	else if (format[i] == '%')
		*counter = *counter + ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_conversion(&args, format, i, &counter);
			i++;
		}
		else
		{
			counter = counter + ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (counter);
}

/*#include <stdio.h>

int	main()
{
	char	a = 'c';
	char str[] = "hello";
	int	b = -5456;
	unsigned int	c = -456;
	int	d = 4785;
	void	*p = str;

	ft_printf("a = %d", ft_printf("*p = %p ", p));
	printf("\n");
	printf("a = %d", printf("*p = %p ", p));
	printf("\n");
	printf("dec = %d, hex = %x, unsi = %u, add = %x", d, d, d, &d);
}*/
