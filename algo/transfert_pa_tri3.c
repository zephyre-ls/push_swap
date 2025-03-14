/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape2_pile.b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:27:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:02:14 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//Envoie pile.b trié décroissante dans pile.a
int	find_max_pos(t_pile *b, int *max_val)
{
	t_pile	*tmp;
	int		pos;
	int		max_pos;

	tmp = b;
	*max_val = b->val;
	pos = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->val > *max_val)
		{
			*max_val = tmp->val;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}

void	push_pa_decroissant(t_pile **a, t_pile **b)
{
	int	max_val;
	int	max_pos;
	int	size_b;

	while (*b)
	{
		size_b = ft_lstsize(*b);
		max_pos = find_max_pos(*b, &max_val);
		rotate_opti(b, max_pos, size_b);
		ft_push_pa(a, b);
	}
}

void	tri_2_elements(t_pile **a)
{
	int	first;
	int	second;

	first = (*a)->val;
	second = (*a)->next->val;
	if (second < first)
		ft_swap_sa(a);
}

//fonction qui trie les 3 derniers elements de a
void	tri_3_elements(t_pile **a)
{
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(*a) == 2)
		return (tri_2_elements(a));
	first = (*a)->val;
	second = (*a)->next->val;
	third = (*a)->next->next->val;
	if (first > second && second < third && first < third)
		ft_swap_sa(a);
	else if (first > second && second > third)
	{
		ft_swap_sa(a);
		ft_reverse_rotate_rra(a);
	}
	else if (first > second && second < third && first > third)
		ft_rotate_ra(a);
	else if (first < second && second > third && first < third)
	{
		ft_swap_sa(a);
		ft_rotate_ra(a);
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_rra(a);
}
