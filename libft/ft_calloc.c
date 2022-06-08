/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:18:28 by usuario           #+#    #+#             */
/*   Updated: 2022/05/07 12:08:34 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	void	*dst;

	tot_size = size * count;
	if ((count == __SIZE_MAX__ && size > 1)
		|| (size == __SIZE_MAX__ && count > 1))
		return (0);
	dst = malloc(tot_size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, tot_size);
	return (dst);
}
