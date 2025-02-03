/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/03 16:41:52 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc <= 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while(i < argc)
	{
		//	ft_check_doublon(argv[i]);
		ft_check_only_num(argv[i]);
		ft_check_max_min_int(argv[i]);
		i++;
	}
	return(0);
}
