/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie_pile_b_after_pb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:27:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 10:44:12 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//quand on push_b on tri pile.b de maniere décroissante
//trouver la position de l'element dans .b
int	trouver_position_in_b(t_pile *b, int val)
{
	int		pos;
	t_pile	*tmp_b;

	pos = 0;
	tmp_b = b;
	while (tmp_b && val < tmp_b->val)
	{
		tmp_b = tmp_b->next;
		pos++;
	}
	return (pos);
}

//rotation opti .b (rb || rrb)
void	rotate_opti(t_pile **b, int pos, int size_b)
{
	if (pos < size_b / 2)
	{
		while (pos > 0)
		{
			ft_rotate_rb(b);
			pos--;
		}
	}
	else
	{
		pos = size_b - pos;
		while (pos > 0)
		{
			ft_reverse_rotate_rrb(b);
			pos--;
		}
	}
}

void	push_pb_trie_optimus(t_pile **a, t_pile **b)
{
	int		val;
	int		size_b;
	int		pos;

	val = (*a)->val;
	size_b = ft_lstsize(*b);
	if (!*b || val > (*b)->val)
	{
		ft_push_pb(b, a);
		return ;
	}
	pos = trouver_position_in_b(*b, val);
	if (pos == 0)
	{
		ft_push_pb(b, a);
		return ;
	}
	rotate_opti(b, pos, size_b);
	ft_push_pb(b, a);
}
