/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/04 13:40:14 by lduflot          ###   ########.fr       */
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

//recherche de la position du PLUS grand element < pivot dans pile a
int	position_max_min_pivot(t_pile *a, int pivot)
{
	int	pos = 0;
	int	max_pos = -1;
	int	max_val = pivot;
	t_pile *tmp_a = a;

	while(tmp_a)
	{
		if(tmp_a->val < pivot && tmp_a->val < max_val)
		{
			max_val = tmp_a->val;
			max_pos = pos;
		}
		tmp_a = tmp_a->next;
		pos++;
	}
	return (max_pos);
	printf("position%d", max_pos);
}

//deplacer element trouvé si_dessus en haut de la pile A 
void	move_max_top_a(t_pile **a, int pos)
{
	if (pos == -1)
		return ;
	int size_a = ft_lstsize(*a);
	int mid = size_a/2;

	if (pos == 1)
		ft_swap_sa(a);
	else if (pos <= mid)
	{
		while (pos > 0)
		{
			ft_rotate_ra(a);
			pos--;
			printf("move_max_top_a_ra");
			print_pile(*a);
		}
	}
	else
	{
		while(pos < size_a)
		{
			ft_reverse_rotate_rra(a);
			pos++;
			printf("mova_max_top_a_rra:");
			print_pile(*a);
		}
	}
}

//transfére l'élement ci_dessus sur la pile b
void	transfer_max_b(t_pile **a, t_pile **b, int pivot)
{
	int	pos_min = position_max_min_pivot(*a, pivot);

	if (pos_min == -1)
  	return;
	move_max_top_a(a, pos_min);
	ft_push_pb(b ,a);

}

//trouver pivot, separe les elements <= pivot
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b)
{
	int	pivot = mediane(*a);

	while(position_max_min_pivot(*a, pivot) != -1)
	{
		transfer_max_b(a, b, pivot);
		if(ft_lstsize(*a) == 3)
			tri_3_elements(a);
	}
}
