/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:39:51 by hakotu            #+#    #+#             */
/*   Updated: 2025/01/20 13:44:18 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_received;

void	confirm(int signal)
{
	if (signal == SIGUSR1)
	{
		g_received = 1;
		ft_printf("acknowledge\n");
	}
}

void	send_char(int pid, char c)
{
	int		shift;
	int		status;

	status = 0;
	shift = 7;
	while (shift >= 0)
	{
		g_received = 0;
		if ((c >> shift & 1) == 1)
			status = kill(pid, SIGUSR1);
		else
			status = kill(pid, SIGUSR2);
		if (status == -1)
			break ;
		if (!g_received)
			pause();
		shift--;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*temp;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong argument number.");
		return (0);
	}
	else if (argv[2][i] == '\0')
	{
		ft_printf("Argument is empty");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	temp = ft_itoa(pid);
	if (ft_strncmp(temp, argv[1], ft_strlen(temp)))
		printf("PID is wrong.");
	signal(SIGUSR1, confirm);
	while (argv[2][i] != '\0')
	{
		send_char(pid, argv[2][i]);
		i++;
	}
}
