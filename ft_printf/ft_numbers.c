/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:14:20 by hakotu            #+#    #+#             */
/*   Updated: 2024/10/30 17:16:19 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfnumbers(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		*(len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putcharlen('-', len);
		ft_printfnumbers(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_printfnumbers(nbr / 10, len);
		ft_putcharlen(nbr % 10 + '0', len);
	}
}

void	ft_unsigned_int(unsigned int x, int *length)
{
	if (x >= 10)
		ft_unsigned_int(x / 10, length);
	ft_putcharlen(x % 10 + '0', length);
}

void	ft_hexadecimal(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharlen('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_character [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharlen(string[i], length);
}

void	ft_pointer(size_t pointer, int *length)
{
	char	string[25];
	char	*base_character;
	int		i;

	if (pointer == 0)
	{
		ft_string("(nil)", length);
		return ;
	}
	ft_string("0x", length);
	base_character = "0123456789abcdef";
	i = 0;
	while (pointer != 0)
	{
		string[i] = base_character [pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putcharlen(string[i], length);
}
