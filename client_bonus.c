/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:57:02 by usuario           #+#    #+#             */
/*   Updated: 2022/07/12 15:00:12 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

#define DELAY 5000

void	send_bits(char *str, int pid)
{
	int	pos;
	int	len;
	int	i;

	len = ft_strlen(str);
	i = -1;
	while (++i <= len)
	{
		pos = -1;
		while (++pos < 7)
		{
			if ((str[i] >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(DELAY);
		}
	}
}

void	error(void)
{
	ft_putstr("Usage :<PID SERVER> <STRING>");
	exit(0);
}
void confirm(int sig)
{
	ft_putstr("message send");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	signal(SIGUSR2, confirm);
	if (argc != 3)
	{
		error();
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_bits(msg, pid);
	return (0);
}
