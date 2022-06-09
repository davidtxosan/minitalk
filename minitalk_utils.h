/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:21:19 by usuario           #+#    #+#             */
/*   Updated: 2022/06/09 17:16:12 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_H
# define MINITALK_UTILS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
#endif
