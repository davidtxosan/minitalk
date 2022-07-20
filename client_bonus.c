/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:57:02 by usuario           #+#    #+#             */
/*   Updated: 2022/07/20 19:39:55 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"

#define DELAY 5000

int	g_len;

void	ft_received(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr("SERVER : Received ");
		ft_putnbr(g_len);
		write(1, " character. \n", 14);
	}
	exit (1);
}

void	send_bits(char str, int pid)
{
	int	i;
	int	j;

	i = 128;
	j = 0;
	(void)pid;
	while (i > 0)
	{
		if ((str & i) == i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i = i / 2;
		usleep(150);
	}
	ft_error("", j);
}

void	error(void)
{
	ft_putstr("Usage :<PID SERVER> <STRING>");
	exit(0);
}

int	main(int argc, char **argv)
{

	if (argc != 3)
	{
		error();
	}
	int	a;
	int	i;

	i = 0;
	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		while (argv[2][i])
			send_bits(argv[2][i++], a);
		send_bits('\0', a);
		g_len = i;
		signal(SIGUSR1, ft_received);
		while (1)
			pause();
	}
}
