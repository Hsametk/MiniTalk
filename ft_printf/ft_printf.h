/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:34:58 by hakotu            #+#    #+#             */
/*   Updated: 2024/10/30 17:17:12 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putcharlen(char c, int *len);
void	ft_string(char *args, int *length);
void	ft_printfnumbers(int nbr, int *len);
void	ft_unsigned_int(unsigned int x, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_pointer(size_t pointer, int *length);

#endif