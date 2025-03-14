/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:27 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 10:54:54 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Premier element au sommet de b go sommet de a;
//tmp_b = *b = recup premier noeud de b
//*b = (*b)->next; =supprime premier element de b;
//ft_lstadd_front(a, tmp_b); = ajout b a a
void	ft_push_pa(t_pile **a, t_pile **b)
{
	t_pile	*tmp_b;

	if (*b != NULL)
	{
		tmp_b = *b;
		*b = (*b)->next;
		ft_lstadd_front(a, tmp_b);
	}
	count_instruction("pa");
}

//Premier element au sommet de a go sommet de b;
void	ft_push_pb(t_pile **b, t_pile **a)
{
	t_pile	*tmp_a;

	if (*a != NULL)
	{
		tmp_a = *a;
		*a = (*a)->next;
		ft_lstadd_front(b, tmp_a);
	}
	count_instruction("pb");
}
