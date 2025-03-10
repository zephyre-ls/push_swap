/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:11:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/09 18:41:51 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quick_sort(t_pile **a, t_pile **b)
{
	while (ft_lstsize(*a) > 3)
		diviser_pour_mieux_regner(a, b);
	if (ft_lstsize(*a) == 3)
		tri_3_elements(a);
	trier_pile_b(a, b);
}

// envoie pile.a dans pile.b jusqu'à qu'il reste 3 elements dans a.
void	diviser_pour_mieux_regner(t_pile **a, t_pile **b)
{
	int	pivot;

	while (ft_lstsize(*a) > 3)
	{
//		printf("taille a: %d\n", ft_lstsize(*a));
		pivot = mediane(*a);
//		printf("pivot: %d\n", pivot);
		transferer_pivot(a, b, pivot);
//		printf("pilea");
//		print_pile(*a);
	}
	if (ft_lstsize(*a) == 3)
			tri_3_elements(a);
}

void	count_instruction(void)
{
	static int	count_instruction = 0;

	count_instruction++;
//	printf("Nbr d'instructions:%d\n", count_instruction);
}
