/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphillip <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:08 by jphillip          #+#    #+#             */
/*   Updated: 2025/03/16 18:06:00 by jphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_conversion(va_list args, const char format);
int		ft_printf(const char *constr, ...);
int		ft_len(int n);
int		ft_putnbr(int n);
int		len_ptr(uintptr_t nb);
int		ft_putptr(uintptr_t ptr);
int		ft_unsigned_len(unsigned int nb);
int		ft_putunsigned(unsigned int nb);
int		hex_len(unsigned int num);
int		ft_puthex(unsigned int num, const char format);
void	ft_put_hex(unsigned int num, const char format);
void	ft_put_ptr(uintptr_t nb);
char	*ft_char(char *s, unsigned int number, int len);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int nb);
#endif
