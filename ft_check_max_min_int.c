/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_max_min_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:37:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/03 16:43:12 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//INT_MIN = -214783648
//INT_MAX = 2147483647
void	ft_check_max_min_int(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (LONG_MAX - (str[i] - '0')) / 10)
		{
			write(1, "Error\n", 6);
			return ;
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
	{
		write(1, "Error\n", 6);
		return ;
	}
}
