/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidsan <davidsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:21:19 by usuario           #+#    #+#             */
/*   Updated: 2022/06/08 17:51:50 by davidsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_symbols(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);

#endif
