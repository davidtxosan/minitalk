/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:29:24 by usuario           #+#    #+#             */
/*   Updated: 2022/05/08 18:34:27 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t		index;
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!s || !f || !(tmp))
		return (NULL);
	index = 0;
	while (index < (ft_strlen((char *)s)))
	{
		tmp[index] = f(index, s[index]);
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}
