/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:56:23 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/06 15:21:21 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exemple pile_a : [2] [4] [1] NULL
//
//		2		4
//		4		1
//		1		2
//		a		a=ra 

//add nouvel element directement au dernier noeud de la list 
void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if(lst == NULL)
		lst = new;
	while(lst->next && lst != NULL)
		lst = lst->next
	lst->next = new;
}

void	ft_rotate_ra(pile *a)
{
	pile	tmp_a;

	tmp_a = a; //recup 1er noeud tmp_a = [2]
	a = a->next; //supp 1er noeud et passe au suivant a = [1]
	ft_lstadd_back(a, tmp_a); //remplace le dernier noeud par le premier 
}

void	ft_rotate_rb(pile *b)
{
	pile	tmp_b;
	tmp_b = b;
	b = b->next;
	ft_lstadd_back(b, tmp_b);
}

void	ft_rotate_rr(pile *a, pile *b)
{
	pile	tmp_a;
	pile tmp_b;

	tmp_a = a;
	a = a->next;
	ft_lstadd_back(a, tmp_a);

	tmp_b = b;
	b = b->next;
	ft_lstadd_back(b, tmp_b);
}
