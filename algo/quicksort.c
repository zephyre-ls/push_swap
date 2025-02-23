/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/23 11:55:56 by lduflot          ###   ########.fr       */
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
int	position_max_sup_pivot(t_pile *a; int pivot)
{
	int	pos = 0;
	int	max_pos = 0;
	t_pile *tmp_a = a;

	while(tmp_a)
	{
		if(tmp_a->val >= pivot && tmp_a->val > max_pos)
			max_pos = pos;
		tmp_a = tmp_a->next;
		pos++;
	}
	return (max_pos);
}
	
//ajouter l'élement ci dessus en haut de la pile a 
void	comparaison_pivot_1(t_pile **a, t_pile **b)
{
	int	pivot = mediane(*a);
	t_pile *tmp_a = *a;
	t_pile *tmp_b = NULL;
	t_pile *next;

	while(tmp_a)
	{
		next = tmp_a->next;
		if(pivot == tmp_a->val || pivot < tmp_a->val)
			diviser_pour_mieux_regner(a, b, pivot);
		else
			tmp_a = tmp_a->next;
	}
}

//transfére l'élement ci_dessus sur la pile b
void	transfer_max_b(t_pile **a, t_pile **b, int pivot)
{

}

void	diviser_pour_mieux_regner(t_pile **a, t_pile **b, int pivot))
{
	t_pile *tmp_a = *a;
	if(a 
//réaliser différente instructions pour que le node remonte en haut de la liste et soit push sur b
//opti b ? stocker dans tmp_b tous les val > pivot et faire passer dans l'ordre decroissant
// donc on stocke déjà tout ce >pivot
// on parcourt la liste 
// quand le plus grand est trouvé on fait les diverses instructions pour le passer au dessus de la liste et push_b
// et on fait ca jusqu'a que tmp_b = NULL.
}
