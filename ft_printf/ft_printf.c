/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:33:20 by hakotu            #+#    #+#             */
/*   Updated: 2024/10/30 17:09:34 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checkformat(char s, va_list *args, int *len, int *i)
{
	if (s == 'c')
		ft_putcharlen(va_arg (*args, int), len);
	else if (s == 's')
		ft_string(va_arg (*args, char *), len);
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_printfnumbers(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putcharlen('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_checkformat(format[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putcharlen(format[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
