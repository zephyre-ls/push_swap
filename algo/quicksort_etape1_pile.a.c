/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape1_pile.a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/25 14:51:12 by lduflot          ###   ########.fr       */
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

//recherche de la position du PLUS grand element > pivot dans pile a
int	position_max_sup_pivot(t_pile *a, int pivot)
{
	int	pos = 0;
	int	max_pos = -1;
	int	max_val = pivot;
	t_pile *tmp_a = a;

	while(tmp_a)
	{
		if(tmp_a->val > pivot && tmp_a->val > max_val)
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
void	move_max_top_a(t_pile **a, t_pile **b, int pos)
{
	if (pos == -1)
		return ;
	int size_a = ft_lstsize(*a);
	if (pos > size_a / 2)
	{
		while (pos < size_a)
		{
			ft_reverse_rotate_rra(a);
			pos++;
		}
	}
	else
	{
		while(pos > 0)
		{
			ft_rotate_ra(a);
			pos--;
		}
	}
	/*int size_b = ft_lstsize(*b);
	if (pos > size_b / 2)
	{
		while (pos < size_b)
		{
			ft_reverse_rotate_rrb(b);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			ft_rotate_rb(b);
			pos--;
		}
	}*/
	if (*b && (*b)->next && (*b)->val < (*b)->next->val)
  	 ft_rotate_rb(b);
}
//trouver le pivot avec mediane
void	comparaison_pivot_1(t_pile **a, t_pile **b)
{
	int	pivot = mediane(*a);
	diviser_pour_mieux_regner(a, b, pivot);
}

//transfére l'élement ci_dessus sur la pile b
void	transfer_max_b(t_pile **a, t_pile **b, int pivot)
{
	//int	pos_max = position_max_sup_pivot(*a, pivot);
	int	pos_min = position_max_sup_pivot(*a, pivot);

	if (pos_min == -1)
  	return;
	move_max_top_a(a, b, pos_min);
	ft_push_pb(b ,a);
// Si b contient plus d'un élément et que le nouveau est plus petit
	if (*b && (*b)->next && (*b)->val < (*b)->next->val)
    ft_rotate_rb(b);

}
//separe les elements >= pivot
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b, int pivot)
{
	while(position_max_sup_pivot(*a, pivot) != -1)
		transfer_max_b(a, b, pivot);
}
