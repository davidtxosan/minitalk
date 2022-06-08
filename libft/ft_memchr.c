/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:54:15 by usuario           #+#    #+#             */
/*   Updated: 2022/05/06 18:11:31 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n)
	{
		if (*((unsigned char *)s + index) == (unsigned char)c)
			return ((void *)s + index);
		index++;
	}
	return (0);
}
