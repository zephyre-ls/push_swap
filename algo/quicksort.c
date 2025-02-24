/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/24 09:30:49 by lduflot          ###   ########.fr       */
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
void	move_max_top_a(t_pile **a, int pos)
{
	if (pos == -1)
		return ;
	while (pos > 0)
	{
		ft_rotate_ra(a);
		pos--;
	}
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
	int	pos_max = position_max_sup_pivot(*a, pivot);

	if (pos_max == -1)
		return ;
	move_max_top_a(a, pos_max);
	ft_push_pb(b ,a);
	    // Si b contient plus d'un élément et que le nouveau est plus petit
    if (*b && (*b)->next && (*b)->val < (*b)->next->val)
        ft_rotate_rb(b);
//	decroissant_b(b);
}

//reorganisation de b par ordre decroissant
/*void	decroissant_b(t_pile **b)
{
	int	len_b = ft_lstsize(*b);
	while(len_b > 1)
	{
		ft_rotate_rb(b);
		len_b--;
	}
}*/

//separe les elements >= pivot
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b, int pivot)
{
	while(position_max_sup_pivot(*a, pivot) != -1)
		transfer_max_b(a, b, pivot);
	//decroissant_b(b);
}


//réaliser différente instructions pour que le node remonte en haut de la liste et soit push sur b
//opti b ? stocker dans tmp_b tous les val > pivot et faire passer dans l'ordre decroissant
// donc on stocke déjà tout ce >pivot
// on parcourt la liste 
// quand le plus grand est trouvé on fait les diverses instructions pour le passer au dessus de la liste et push_b
// et on fait ca jusqu'a que tmp_b = NULL.
//mince pas possible de faire ca car je crée une nouvelle liste
// on regarde >= pivot
// on cherche la position de la valeur la plus haute
// on fait les instructions pour la mettre en haut de a 
// on push sur b 
// et ainsi de suite .........;

