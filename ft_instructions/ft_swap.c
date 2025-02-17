/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:54:46 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/16 20:44:37 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//intervertit les 2 premiers elements au sommet de la pile a
void	*ft_swap_sa(t_pile *a)
{
	t_pile *tmp_a;

	if(a != NULL && a->next)
	{
		//exe;mple pile_a : [3] [2] NULL

		tmp_a = a->next; // tmp = [2] 
		a = a->next; //logiquement a = [3] NULL et le [2] et sup
		ft_lstadd_front(a, tmp_a);
	}
	return (NULL);
}

//intervertit les 2 premiers elements au sommet de la pile b
void	*ft_swap_sb(t_pile *b) 
{
	t_pile *tmp_b;

	if (b != NULL && b->next)
	{
		tmp_b = b->next;
		b = b->next;
		ft_lstadd_front(b, tmp_b);
	}
	return (NULL);
}

//sa + sb
void	*ft_swap_ss(t_pile *a, t_pile *b)
{
	ft_swap_sa(a);
	ft_swap_sb(b);
	return (NULL);
}
