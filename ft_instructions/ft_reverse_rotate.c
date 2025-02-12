/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:48 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/12 12:23:52 by lduflot          ###   ########.fr       */
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
		pile *tmp_a;

		tmp_a = ft_lstlast(a); //tmp_a = 1
		*a = ft_lstadd_front(a, tmp_a); a = 124// a = [1] [2] [4] [1] = 1 de fin doit etre supprimer
		(*a)->next = NULL;
}

void	ft_reverse_rotate_rrb(t_pile **b)
{
	pile *tmp_b;
	tmp_b = ft_lstlast(b);
	*b = ft_lstadd_front(b, tmp_b);
	(*b)->next = NULL;

}

void	ft_reverse_rotate_rrr(t_pile **a, t_pile **b)
{
	ft_reverse_rotate_rra(a);
	ft_reverse_rotate_rrb(b);
}

#include <stdio.h>

int	main(void)
{
	piles *test = NULL;
	test = malloc(sizeof(test));
	test->val = 1;
	test->next = 4;
	test->next = 5;
	test->next = NULL;
	printf("%ls", piles);
	return (0);
}


