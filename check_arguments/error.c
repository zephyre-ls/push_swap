/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:03:12 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 10:30:48 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

char	**ft_freemallocerror(char **bigtab)
{
	size_t	i;

	i = 0;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
	return (NULL);
}
