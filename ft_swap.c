/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/07 10:36:28 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//intervertit les 2 premiers elements au sommet de la pile a
void	ft_swap_sa(pile **a)
{
	pile *tmp_a;

	if(*a != NULL && *a->next)
	{
		//exe;mple pile_a : [3] [2] NULL

		tmp_a = *a->next; // tmp = [2] 
		*a = (*a)->next; //logiquement a = [3] NULL et le [2] et sup
		ft_lstadd_front(a, tmp_a);
	}
}

//intervertit les 2 premiers elements au sommet de la pile b
void	ft_swap_sb(pile *b) 
{
	pile *tmp_b;

	if (b != NULL && b->next))
	{
		tmp_b = *b->next;
		*b = (*b)->next;
		ft_lstaad_front(b, tmp_b);
	}
}

//sa + sb
void	ft_swap_ss(pile *a, pile *b)
{
	pile	*tmp_a;
	pile *tmp_b;
	
	if (a != NULL && a->next))
	{
		tmp_a = a->next;
		a = a->next;
		ft_lstaad_front(a, tmp_a);
	}
	if (b != NULL && b->next))
	{
		tmp_b = b->next;
		b = b->next;
		ft_lstaad_front(b, tmp_b);
	}
}
