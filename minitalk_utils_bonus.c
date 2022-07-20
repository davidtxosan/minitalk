/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:01:41 by usuario           #+#    #+#             */
/*   Updated: 2022/07/20 19:35:04 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_utils_bonus.h"

void	ft_error(const char *str, int flag)
{
	while (*str)
	{
		if (*str != 32)
		{
			ft_putstr("Error : Enter correct pid \n");
			exit (1);
		}
		str++;
	}
	if (flag == -1)
	{
		ft_putstr("Error : Enter correct pid \n");
		exit (1);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r *= 10;
		r += str[i] - 48;
		i++;
	}
	return (r * s);
}

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr < 10)
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str [c])
	c++;
	return (c);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
