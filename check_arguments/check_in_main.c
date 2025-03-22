/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:22:52 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/22 10:30:39 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	if_argc_is_2(char **argv, t_pile **a)
{
	int		i;
	char	**arg_split;

	i = 0;
	arg_split = ft_split(argv[1]);
	if (arg_split == NULL || arg_split[0] == NULL)
		error();
	while (arg_split[i])
	{
		ft_check_only_num(arg_split[i]);
		ft_check_max_min_int(arg_split[i]);
		i++;
	}
	ft_check_doublon(i, arg_split);
	ft_check_tri(arg_split);
	i = 0;
	init_pile(a, i, arg_split);
	ft_free_split(arg_split);
}

void	if_argc_more_than_2(int argc, char **argv, t_pile **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_check_only_num(argv[i]);
		ft_check_max_min_int(argv[i]);
		i++;
	}
	ft_check_tri(argv);
	ft_check_doublon(argc, argv);
	i = 1;
	init_pile(a, i, argv);
}
