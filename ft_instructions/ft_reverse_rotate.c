/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:48 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/19 18:24:53 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//https://miage.univ-nantes.fr/miage/DVD-MIAGEv2/Algo_files/DVDMIAGE_Algo_Chapitre_10_Listes.pdf
//exemple pile_a : [2] [4] [1] NULL
//		2		1
//		4		2
//		1		4
//		a		a=ra
void	ft_reverse_rotate_rra(t_pile **a)
{
	t_pile *last;
	t_pile *before_last;

	if (*a == NULL || (*a)->next == NULL)
		return;

	before_last = ft_lstbefore_last(*a); // Trouve l’avant-dernier
	last = ft_lstlast(*a); // Trouve le dernier
	
	before_last->next = NULL; // Coupe le lien avec le dernier
	
	ft_lstadd_front(a, last); // Ajoute le dernier au début
}

void	ft_reverse_rotate_rrb(t_pile **b)
{
	t_pile *last;
	t_pile *before_last;

	if (*b == NULL || (*b)->next == NULL)
		return;

	before_last = ft_lstbefore_last(*b);
	last = ft_lstlast(*b);
	before_last->next = NULL;
	ft_lstadd_front(b, last);
}

void	ft_reverse_rotate_rrr(t_pile **a, t_pile **b)
{
	ft_reverse_rotate_rra(a);
	ft_reverse_rotate_rrb(b);
}
