/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/09 18:41:59 by lduflot          ###   ########.fr       */
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
void	transferer_pivot(t_pile **a, t_pile **b, int pivot)
{
	int	size;
	int	i;
//	int	rotations;
	int	last_moved;

	size = ft_lstsize(*a);
	i = 0;
	//rotations = 0;
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
			ft_rotate_ra(a);
			//rotations++;
			last_moved++;
		}
		if (last_moved > size * 2)
			break;
		size = ft_lstsize(*a);
	//	printf("taille a aprés opération: %d\n", size);
		//if (rotations > size * 2 && last_moved == 0)
		if (size == 3)	
			tri_3_elements(a);
	}
}
