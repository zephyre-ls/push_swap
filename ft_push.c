/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:27 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/06 15:55:32 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Exemple = pile_a : [3] -> [8] -> [5] -> NULL
//					pile_b : [2] -> [6] -> NULL 
//					2 et 3 represente les sommets des piles a et b 
//						3	
//						8		2
//						5		6
//						a		b

//Premier element au sommet de b go sommet de a;
void	ft_push_pa(pile *a, pile *b)
{
	pile *tmp_b;
//	pile *first_a;

	if (b != NULL)
	{
		tmp_b = b; //recup premier noeud de b
		b = b->next;//supprime premier element de b;
		ft_lstadd_front(a, tmp_b); // ajout b a a 
	}
}

//Premier element au sommet de a go sommet de b;
void	ft_push_pb(pile *b, pile *a)
{
	pile	*tmp_a;

	if(*a != NULL)
	{
		tmp_a = a;
		a = a->next;
		ft_lstadd_front(b, tmp_a);
	}
}

