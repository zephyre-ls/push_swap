/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:13:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:12:06 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// calcul de 3 pivots répartis entre la valeur min et max de pile.a
void	calculer_pivots(t_pile *a, t_pivots *pivots)
{
	t_pile	*tmp;
	t_pile	*tmp_little;
	t_pile	*tmp_big;
	int		big_min;

	tmp = a;
	tmp_little = a;
	tmp_big = a;
	while (tmp)
	{
		if (tmp->val > tmp_big->val)
			tmp_big = tmp;
		else if (tmp->val < tmp_little->val)
			tmp_little = tmp;
		tmp = tmp->next;
	}
	big_min = tmp_big->val - tmp_little->val;
	pivots->pivot1 = tmp_little->val + big_min / 3;
	pivots->pivot2 = tmp_little->val + big_min / 2;
	pivots->pivot3 = tmp_little->val + 2 * big_min / 3;
}

void	found_pivot(int val, int *first, int *second, int *third)
{
	if (val > *first)
	{
		*third = *second;
		*second = *first;
		*first = val;
	}
	else if (val > *second)
	{
		*third = *second;
		*second = val;
	}
	else if (val > *third)
		*third = val;
}
// calcul du 3 plus grand élément de pile.a lorsqu'il ne reste que 10 elem
int	pivot_10(t_pile *a)
{
	t_pile	*tmp_a;
	int		first;
	int		second;
	int		third;

	tmp_a = a;
	first = 0;
	second = 0;
	while (tmp_a)
	{
		found_pivot(tmp_a->val, &first, &second, &third);
		tmp_a = tmp_a->next;
	}
	return (third);
}
