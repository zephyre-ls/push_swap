/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/24 10:41:25 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//intervertit les 2 premiers elements au sommet de la pile a
//tmp_a = (*a)->next;   // Stocke [2]
//(*a)->next = tmp_a->next;  // [3] doit pointer vers NULL ou le suivant
//tmp_a->next = *a;  // [2] pointe vers [3]
//*a = tmp_a;  // *a devient [2]

void	ft_swap_sa(t_pile **a)
{
	t_pile	*tmp_a;

	if (*a != NULL && (*a)->next)
	{
		tmp_a = (*a)->next;
		(*a)->next = tmp_a->next;
		tmp_a->next = *a;
		*a = tmp_a;
	}
	write(1, "sa", 2);
	write(1, "\n", 1);
}

//intervertit les 2 premiers elements au sommet de la pile b
void	ft_swap_sb(t_pile **b)
{
	t_pile	*tmp_b;

	if (*b != NULL && (*b)->next)
	{
		tmp_b = (*b)->next;
		(*b)->next = tmp_b->next;
		tmp_b->next = *b;
		*b = tmp_b;
	}
	write(1, "sb", 2);
	write(1, "\n", 1);
}

//sa + sb
void	ft_swap_ss(t_pile **a, t_pile **b)
{
	ft_swap_sa(a);
	ft_swap_sb(b);
	write(1, "ss", 2);
	write(1, "\n", 1);
}
