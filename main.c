/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/12 12:12:56 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i = 1;
	char	**arg_split;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		arg_split = ft_split(argv[1]);
		if (arg_split == NULL || arg_split[0] == NULL || arg_split[1] == NULL)
		{
			write(1, "Error\n", 6);
			return(0);
		}
		i = 0;
		while (arg_split[i])
		{
			//printf("arg_split[%d]: '%s'\n", i, arg_split[i]);
			ft_check_only_num(arg_split[i]);
			ft_check_max_min_int(arg_split[i]);
			i++;
		}
		ft_check_doublon(i, arg_split);
		ft_freemallocerror(arg_split);  
	}
	else
	{
		while(i < argc)
		{
			ft_check_only_num(argv[i]);
			ft_check_max_min_int(argv[i]);
			i++;
		}
		ft_check_doublon(argc, argv);
	}
	return(0);
}
