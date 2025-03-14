/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:18:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 10:18:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_pile **a, t_pile **b)
{
	while (ft_lstsize(*a) > 3)
		diviser_pour_mieux_regner(a, b);
	if (ft_lstsize(*a) == 3 || ft_lstsize(*a) == 2)
		tri_3_elements(a);
	push_pa_decroissant(a, b);
}

// envoie pile.a dans pile.b jusqu'à qu'il reste 3 elements dans a.
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b)
{
	t_pivots	pivots;
	int			pivot10;

	while (ft_lstsize(*a) > 11 && ft_lstsize(*a) > 3)
	{
		calculer_pivots(*a, &pivots);
		transferer_pivot(a, b, &pivots);
		calculer_pivots(*a, &pivots);
	}
	while (ft_lstsize(*a) <= 11 && ft_lstsize(*a) > 3)
	{
		pivot10 = pivot_10(*a);
		transferer_pivot10(a, b, pivot10);
	}
	if (ft_lstsize(*a) == 3 || ft_lstsize(*a) == 2)
		tri_3_elements(a);
}
