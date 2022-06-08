/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:27:35 by davidsan          #+#    #+#             */
/*   Updated: 2022/04/30 11:36:39 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_symbols(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
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
