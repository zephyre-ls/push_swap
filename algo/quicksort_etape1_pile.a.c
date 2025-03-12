/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 14:13:39 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Quicksort / Tri rapide / Tri pivot
= DIVISER POUR REGNER;
En ce moment:
- Mediane calculer avec +/- nombres de la liste
- Envoie dans pile.b le plus grand avant pivot.
- pile.b se retrouve décroissante
- qd 3 nombres dans pile.a trie3elemen
- puis push b. dans a.
PROBLEMES = 
* nombreux rra et ra (pour envoyé le plus grand dans .b)
* nombreux pa/pb lors des push 
 == MAUVAISE OPTIMISATIONS
*/

#include "../push_swap.h"

/* 
** envoie les nombres inf au pivot dans pile.b
** last_moved = variable pour suivre si un element a été déplacé
** 1er boucle = continue jusqu'a push tous les nombre a dans b
** on push des qu'inf au pivot
** si valeur >= pivot on rotate (opti swap? rra?)
** si aucun element déplacé aprés un certain nombre de rotate = break;
*/

int	position_inferieur_pivot(t_pile *a, int pivot)
{
	int	pos = 0;
	t_pile *tmp_a = a;

	while (tmp_a)
	{
		if(tmp_a->val < pivot)
			return (pos) ; 
		tmp_a = tmp_a->next;
		pos++;
	}
	return (-1);
}


void	move_first_elem_inf_pivot(t_pile **a, int pos)
{
	if (pos == -1)
		return ;
	int	size_a = ft_lstsize(*a);
	int	mid = size_a/2;

	if (pos == 0)
		return ;
	else if (pos == 1)
		ft_rotate_ra(a);
	else if (pos <= mid)
	{
		while (pos > 0)
		{
			ft_rotate_ra(a);
			pos--;
		}
	}
	else
	{
		while (pos < size_a)
		{
			ft_reverse_rotate_rra(a);
			pos++;
		}
	}
}

void	transferer_pivot(t_pile **a, t_pile **b, int pivot)
{
	int	size;
	int	i; 
	int	last_moved;

	size = ft_lstsize(*a);
	i = 0;
	last_moved = 0;
	while (size > 3)
	{
		if ((*a)->val < pivot)
		{
			push_pb_trie_optimus(a, b);
			i++;
			last_moved = 0;
		}
		else
		{
			int	pos =	position_inferieur_pivot(*a, pivot);
			move_first_elem_inf_pivot(a, pos);
			last_moved++;
		}
		if (last_moved > size)
			break;
		size = ft_lstsize(*a);
	//	printf("taille pivot %d\n", pivot);
	//	print_pile(*a);
	//	printf("taille a aprés opération: %d\n", size);
	//	print_pile(*a);
		if (size == 3)
			tri_3_elements(a);
	}
}

/*void	ft_rotate_rr_if_possible(t_pile **a, t_pile **b, int *ra_count, int *rb_count)
{
	int	rr_count;

	rr_count = -1;

	printf("ra_count = %d, rb_count = %d\n", *ra_count, *rb_count);
	if (*ra_count == -1)
		*ra_count = 0;
  if (*rb_count == -1)
		*rb_count = 0;
	if (*ra_count > 0 && *rb_count > 0)
	{
		printf("entre dans rr\n");
		ft_rotate_rr(a, b);
		(*ra_count)--;
		(*rb_count)--;
	}
	else if (*ra_count > *rb_count)
	{
		printf("entre dans ra\n");
		ft_rotate_ra(a);
		(*ra_count)--;
	}
	else if (*rb_count > *ra_count)
	{
		printf("entre dans rb\n");
		ft_rotate_rb(b);
		(*rb_count)--;
	}
}*/
