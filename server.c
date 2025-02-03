/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:01:58 by hakotu            #+#    #+#             */
/*   Updated: 2025/01/20 12:27:14 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		g_count;

void	handle(int signal, siginfo_t *info, void *context)
{
	static char	c;

	(void)context;
	c = c << 1;
	if (signal == SIGUSR1)
		c = c | 1;
	else if (signal == SIGUSR2)
		c = c | 0;
	g_count++;
	if (g_count == 8)
	{
		ft_printf("%c", c);
		g_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	a;

	g_count = 0;
	a.sa_sigaction = handle;
	a.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
	ft_printf("Your PID is:%d\n", getpid());
	while (1)
		pause();
}
