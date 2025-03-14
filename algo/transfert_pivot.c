/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:21:02 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_element(t_pile **a, t_pile **b, t_pivots *pivots, int *last_moved)
{
	int	pos;

	if ((*a)->val <= pivots->pivot1)
	{
		push_pb_trie_optimus(a, b);
		*last_moved = 0;
	}
	else
	{
		pos = position_inferieur_pivot(*a, pivots->pivot1);
		move_first_elem_inf_pivot(a, pos);
		(*last_moved)++;
	}
}

void	transferer_pivot(t_pile **a, t_pile **b, t_pivots *pivots)
{
	int	size;
	int	last_moved;

	last_moved = 0;
	size = ft_lstsize(*a);
	while (size > 3)
	{
		move_element(a, b, pivots, &last_moved);
		if (last_moved > 0)
			break ;
		size = ft_lstsize(*a);
		if (size == 3)
			tri_3_elements(a);
	}
}

void	move_or_push(t_pile **a, t_pile **b, int pivot, int *last_moved)
{
	int	pos;

	if ((*a)->val < pivot)
	{
		push_pb_trie_optimus(a, b);
		*last_moved = 0;
	}
	else
	{
		pos = position_inferieur_pivot(*a, pivot);
		move_first_elem_inf_pivot(a, pos);
		(*last_moved)++;
	}
}

void	transferer_pivot10(t_pile **a, t_pile **b, int pivot)
{
	int	size;
	int	last_moved;

	size = ft_lstsize(*a);
	last_moved = 0;
	while (size > 3)
	{
		move_or_push(a, b, pivot, &last_moved);
		if (last_moved > size)
			break ;
	}
	if (size == 3)
		tri_3_elements(a);
}
