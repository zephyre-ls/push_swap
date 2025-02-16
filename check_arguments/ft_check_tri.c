/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:15:00 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/16 23:50:09 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_tri(char **argv)
{
	int	i;
	int	previous;
	int	next;

	i = 1;
	while(argv[i + 1])
	{
		previous = atoi(argv[i]);
		next = atoi(argv[i + 1]);
		if(previous > next)
			return;
		i++;
	}
	error();
}
