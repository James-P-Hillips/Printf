/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphillip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:33:26 by jphillip          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:40 by jphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (len);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_put_ptr(nb / 16);
		ft_put_ptr(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar((nb + '0'));
		else
			ft_putchar((nb - 10 + 'a'));
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	char_printed;

	char_printed = 0;
	if (ptr == 0)
	{
		char_printed += write(1, "(nil)", 5);
	}
	else
	{
		char_printed += write(1, "0x", 2);
		ft_put_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}
