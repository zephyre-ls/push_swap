/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:15:00 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/22 08:26:57 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_tri(char **argv)
{
	int	i;
	int	previous;
	int	next;

	i = 0;
	while (argv[i + 1])
	{
		previous = ft_atoi(argv[i + 1]);
		next = ft_atoi(argv[i]);
		if (previous > next)
			return ;
		i++;
	}
	exit(EXIT_FAILURE);
}
