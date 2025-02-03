/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:05:39 by hakotu            #+#    #+#             */
/*   Updated: 2024/10/22 11:54:15 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*arr;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	arr = malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	arr[len] = '\0';
	while (nbr > 0)
	{
		arr[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		arr[0] = '-';
	if (n == 0)
		arr[0] = '0';
	return (arr);
}
