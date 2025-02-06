/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:55:48 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/06 16:43:57 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//https://miage.univ-nantes.fr/miage/DVD-MIAGEv2/Algo_files/DVDMIAGE_Algo_Chapitre_10_Listes.pdf
//exemple pile_a : [2] [4] [1] NULL
//
//		2		1
//		4		2
//		1		4
//		a		a=ra 

void	ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	if(lst != NULL)
	{
		while(lst->next != NULL)
		{	
			lst = lst->next;
			i++;
		}
		return(lst)
}

void	ft_reverse_rotate_rra(pile *a)
{
		pile tmp_a;

		tmp_a = ft_lstlast(a); //tmp_a = 1
		a = ft_lstadd_front(a, tmp_a); // a = [1] [2] [4] [1] = 1 de fin doit etre supprimer
		//
}

void	ft_reverse_rotate_rrb(pile *b)
{

}

void	ft_reverse_rotate_rrr(pile *a, pile *b)
{
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if(lst == NULL)
		lst = new;
	while(lst->next && lst != NULL)
		lst = lst->next
	lst->next = new;
}

