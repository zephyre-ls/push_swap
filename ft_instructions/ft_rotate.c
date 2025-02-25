/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:56:23 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/25 14:46:46 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//exemple pile_a : [2] [4] [1] NULL
//		2		4
//		4		1
//		1		2
//		a		a=ra
//tmp_a = *a; //recup 1er noeud tmp_a = [2]
//*a = (*a)->next; //supp 1er noeud et passe au suivant a = [4]
//() permet de garder l'ordre des operations correcte, 
//si abs = *a =*a->next cc *a=*(a->next)
//tmp_a->next=NULL;
//ft_lstadd_back(a, tmp_a); //remplace le dernier noeud par le premier

void	ft_rotate_ra(t_pile **a)
{
	t_pile	*tmp_a;

	tmp_a = *a;
	*a = (*a)->next;
	tmp_a->next = NULL;
	ft_lstadd_back(a, tmp_a);
	write(1, "ra\n", 3);
}

void	ft_rotate_rb(t_pile **b)
{
	t_pile	*tmp_b;

	tmp_b = *b;
	*b = (*b)->next;
	tmp_b->next = NULL;
	ft_lstadd_back(b, tmp_b);
	write(1, "rb\n", 3);
}

void	ft_rotate_rr(t_pile **a, t_pile **b)
{
	ft_rotate_ra(a);
	ft_rotate_rb(b);
	write(1, "rr\n", 3);
}
