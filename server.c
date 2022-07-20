/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:20:20 by usuario           #+#    #+#             */
/*   Updated: 2022/07/20 18:53:20 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

 void	send(int signal)
{
	static char	c = 0;
	static int	position = 0;
	int			bit;

	if (signal == SIGUSR1)
		bit = 0;
	else if (signal == SIGUSR2)
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
	
	signal(SIGUSR1, send);
	signal(SIGUSR2, send);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
	return (0);
}
