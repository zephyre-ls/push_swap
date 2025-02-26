/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/26 09:52:27 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Quicksort / Tri rapide / Tri pivot
= DIVISER POUR REGNER; 
On choisit un élement (pivot) et on réorganise les éléments autours.
Les nombres plus petit que le pivot iront a gauche et inverse à droite. 
Le pivot est en regle général le dernier nombre de la liste chaine. 
Reflexion: possibilité de faire une mediane entre le plus grand et le plus petit.
Cette mediane représente alors le pivot. 
On change de pivot jusqu'à une réorganisation completement croissante 
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
			print_pile(*a);
		}
	}
	else
	{
		while(pos < size_a)
		{
			ft_reverse_rotate_rra(a);
			pos++;
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
		transfer_max_b(a, b, pivot);
}
