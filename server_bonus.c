/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:57:19 by usuario           #+#    #+#             */
/*   Updated: 2022/07/20 19:40:05 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"

void	handler(int sig, siginfo_t *info, void *ptr)
{
	static int	i;
	static char	c;

	(void)ptr;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		if (!c)
		{
			usleep(300);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{

	struct sigaction	sa;

	ft_putstr("Server PID: \n");
	ft_putnbr(getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}