/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape2_pile.b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:27:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/10 20:06:32 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// quand on push_b on tri pile.b de maniere décroissante
void	push_pb_trie_optimus(t_pile **a, t_pile **b)
{
	int		val;
	int		size_b;
	int		pos;
	t_pile	*tmp_b;

	size_b = ft_lstsize(*b);
	pos = 0;
	tmp_b = *b;
	val = (*a)->val;
	if (!*b)
	{
		ft_push_pb(b, a);
		return ;
	}
	if (val > (*b)->val)
		ft_push_pb(b, a);
	else
	{
		while (tmp_b && val < tmp_b->val)
		{
			tmp_b = tmp_b->next;
			pos++;
		}
	//	if (pos == 1)
	//		ft_swap_sb(b);
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
		ft_push_pb(b, a);
	}
}

//Envoie pile.b trié décroissante dans pile.a
void	trier_pile_b(t_pile **a, t_pile **b)
{
	int		max_val;
	int		pos;
	int		max_pos;
	t_pile	*tmp_b;

	while (*b)
	{
		max_val = (*b)->val;
		tmp_b = *b;
		pos = 0;
		max_pos = 0;
		while (tmp_b)
		{
			if (tmp_b->val > max_val)
			{
				max_val = tmp_b->val;
				max_pos = pos;
			}
			tmp_b = tmp_b->next;
			pos++;
		}
		//if (pos == 1)
		//	ft_swap_sb(b);
		if (max_pos < pos / 2)
		{
			while ((*b)->val != max_val)
				ft_rotate_rb(b);
		}
		else
		{
			while ((*b)->val != max_val)
				ft_reverse_rotate_rrb(b);
		}
		ft_push_pa(a, b);
	}
}

//fonction qui trie les 3 derniers elements de a
void	tri_3_elements(t_pile **a)
{
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(*a) == 2)
	{
		first = (*a)->val;
		second = (*a)->next->val;
		if (second < first)
			ft_swap_sa(a);
	}
	if(ft_lstsize(*a) == 3)
	{
	printf("tri_3_element non trie\n");
	print_pile(*a);
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
	printf("tri_3_elemen\n");
	print_pile(*a);
	}
}
