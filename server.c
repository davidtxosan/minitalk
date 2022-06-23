/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:20:20 by usuario           #+#    #+#             */
/*   Updated: 2022/06/23 13:29:45 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send(int sig)
{
	int			bit;
	static int	position = 0;
	static char	c = 0;

	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
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
	struct sigaction	sa;

	sa.sa_handler = send;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
}
