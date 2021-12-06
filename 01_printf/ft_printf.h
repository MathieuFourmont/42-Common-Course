/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:48:40 by mmaxime-          #+#    #+#             */
/*   Updated: 2021/11/30 09:53:00 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

int		ft_printf(const char *format, ...);
void	ft_conversion(va_list *args, const char *format, int i, int *counter);
int		ft_puthex(unsigned long nb);
int		ft_puthex_up(unsigned long nb);
int		ft_puthex_ptr(void *nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);

#endif
