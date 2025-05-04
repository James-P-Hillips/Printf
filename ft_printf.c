/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphillip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:28:40 by jphillip          #+#    #+#             */
/*   Updated: 2025/03/17 13:23:37 by jphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_conversion(va_list args, const char format)
{
	int	char_printed;

	char_printed = 0;
	if (format == 'c')
		char_printed += ft_putchar(va_arg(args, int));
	else if (format == 's')
		char_printed += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		char_printed += ft_putptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		char_printed += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		char_printed += ft_putunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		char_printed += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *constr, ...)
{
	int		i;
	va_list	args;
	int		char_printed;

	va_start(args, constr);
	i = 0;
	char_printed = 0;
	while (constr[i] != '\0')
	{
		if (constr[i] == '%')
		{
			char_printed += ft_conversion(args, constr[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(constr[i]);
		i++;
	}
	va_end(args);
	return (char_printed);
}
