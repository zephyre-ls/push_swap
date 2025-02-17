/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+   e       +:+   */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:06:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/17 17:49:34 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//verification que TOUS les arguments soient differents les uns des autres.
void	ft_check_doublon(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			k = 0;
			while (argv[i][k] != '\0' && argv[j][k] != '\0'
				&& argv[i][k] == argv[j][k])
				k++;
			if (argv[i][k] == '\0' && argv[j][k] == '\0' && k > 0)
			{
				write(1, "Error\n", 6);
				exit(EXIT_FAILURE) ;
			}
			j++;
		}
		i++;
	}
}
