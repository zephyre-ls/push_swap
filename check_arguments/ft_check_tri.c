/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:15:00 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/21 10:05:06 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_tri(char **argv)
{
	int	i;
	int	previous;
	int	next;

	i = 1;
	while (argv[i + 1])
	{
		previous = ft_atoi(argv[i]);
		next = ft_atoi(argv[i + 1]);
		if (previous > next)
			return ;
		i++;
	}
	exit(EXIT_FAILURE);
}
