/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:19:15 by usuario           #+#    #+#             */
/*   Updated: 2022/05/13 16:44:59 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen <= start)
	{
		ret = (char *) malloc(sizeof(char));
		*ret = 0;
		return (ret);
	}
	if (slen - start < len)
		len = slen - start;
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}
