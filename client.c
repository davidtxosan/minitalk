/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:14 by davidsan          #+#    #+#             */
/*   Updated: 2022/06/08 17:50:41 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send_b(char i, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (i >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}
void	send_mess(char *str, int pid)
{
	int i;
	
	i = -1;
	while(str[++i])
	{
		send_b(str[i], pid);
	}
}
void error(void)
{
	ft_putstr("Usage :<PID SERVER> <STRING>");
	exit(0);
}

int	main(int argc, char **argv)
{
	int pid;
	char *msg;
	if (argc !=3)
	{
		error();
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_mess(msg, pid);
	return (0);
}