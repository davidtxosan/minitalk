/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:14 by davidsan          #+#    #+#             */
/*   Updated: 2022/06/09 16:32:49 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils.h"

void	send_bits(char *argv, int pid)
{
	size_t	len;
	size_t	i;
	int		pos;

	len = ft_strlen(argv);
	i = 0;
	while (++i < len)
	{
		pos = 0;
		while (++pos < 8)
		{
			if ((argv[i] >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

void	error(void)
{
	ft_putstr("Usage :<PID SERVER> <STRING>");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;

	if (argc != 3)
	{
		error();
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_bits(msg, pid);
	return (0);
}
