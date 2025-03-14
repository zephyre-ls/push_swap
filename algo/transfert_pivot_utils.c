/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:15:51 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:20:41 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	position_inferieur_pivot(t_pile *a, int pivot)
{
	int		pos;
	t_pile	*tmp_a;

	pos = 0;
	tmp_a = a;
	while (tmp_a)
	{
		if (tmp_a->val < pivot)
			return (pos);
		tmp_a = tmp_a->next;
		pos++;
	}
	return (-1);
}

void	move_first_elem_inf_pivot(t_pile **a, int pos)
{
	int	size_a;
	int	mid;

	size_a = ft_lstsize(*a);
	mid = size_a / 2;
	if (pos == -1 || pos == 0)
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
