/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:20:20 by usuario           #+#    #+#             */
/*   Updated: 2022/06/09 17:27:36 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send(int sig, siginfo_t *info, void *context)
{
	int			bit;
	static int	position;
	static char	c;
	(void)context;

	position = 0;
	c = 0;
	if (sig == SIGUSR1)
		bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	else
		exit(EXIT_FAILURE);
	c += bit << position++;
	if (position == 7)
	{
		if (!c)
			c = '\n';
		ft_putchar(c);
		c = 0;
		position = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	saction;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	saction.sa_sigaction = &send;
	sigaction(SIGUSR1, &saction, NULL);
	sigaction(SIGUSR2, &saction, NULL);
	while (1)
		sleep(1);
}
