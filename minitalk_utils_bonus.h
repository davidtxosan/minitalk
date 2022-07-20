/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:14:18 by usuario           #+#    #+#             */
/*   Updated: 2022/07/20 19:41:31 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_UTILS_BONUS_H
# define MINITALK_UTILS_BONUS_H

# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_error(const char *str, int flag);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
#endif
