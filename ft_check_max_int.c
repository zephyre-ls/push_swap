/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_max_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:37:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/01/30 16:43:45 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_max_int(char *str)
{
	int	i;

	i = 0;
	while (str[i] != "/0")
		i++;
	if (str == INT_MAX)
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
