/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:27 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/19 21:35:49 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Premier element au sommet de b go sommet de a;
void	ft_push_pa(t_pile **a, t_pile **b)
{
	t_pile *tmp_b;
//	pile *first_a;

	if (*b != NULL)
	{
		tmp_b = *b; //recup premier noeud de b
		*b = (*b)->next;//supprime premier element de b;
		ft_lstadd_front(a, tmp_b); // ajout b a a
	}
}

//Premier element au sommet de a go sommet de b;
void	ft_push_pb(t_pile **b, t_pile **a)
{
	t_pile	*tmp_a;

	if(*a != NULL)
	{
		tmp_a = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, tmp_a);
	}
}
