/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:41:17 by davidsan          #+#    #+#             */
/*   Updated: 2022/06/08 17:41:44 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk_utils.h"

int		ft_symbols(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	return (i);
}
int		ft_atoi(const char *str)
{
	int	c;
	int	neg;
	int	num;

	c = ft_symbols(str);
	neg = 1;
	num = 0;
	if (str[c] == '-')
		neg = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (ft_isdigit(str[c]))
	{
		num *= 10;
		num += str[c] - 48;
		c++;
	}
	num *= neg;
	return (num);
}
int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
