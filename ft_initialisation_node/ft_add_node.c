/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:04:16 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/17 17:38:10 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_pile(t_pile **a, int argc, char **argv)
{
	int	i;
	int	val;
	t_pile *new_node;

	i = 1; //evite le nom du programme
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		new_node = ft_lstnew(val);
		if(new_node == NULL)
		{
			freepile(*a);
			return ;
		}
		ft_lstadd_front(*a, new_node);
		i++;
	}
	printf("init_pile appele\n");
}

void	freepile(t_pile *a)
{
	t_pile *tmp;

	while(a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}
