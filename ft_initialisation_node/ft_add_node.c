/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:04:16 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/21 10:34:56 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_pile(t_pile **a, int i, char **argv)
{
	int		val;
	t_pile	*new_node;

	while (argv[i])
	{
		val = ft_atoi(argv[i]);
		new_node = ft_lstnew(val);
		if (new_node == NULL)
		{
			freepile (*a);
			return ;
		}
		ft_lstadd_back(a, new_node);
		i++;
	}
}

void	freepile(t_pile *a)
{
	t_pile	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
