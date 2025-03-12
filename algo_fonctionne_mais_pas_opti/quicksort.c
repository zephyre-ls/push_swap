/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:11:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 14:08:45 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    quick_sort(t_pile **a, t_pile **b)
{
	int	size_a;

	while ((size_a = ft_lstsize(*a)) > 3)
  {
		diviser_pour_mieux_regner(a, b);
		printf("diviser pour mieux regner:");
    print_pile(*a);
		print_pile(*b);
  }
	/*if (ft_lstsize(*a) == 3)
	{
		print_pile(*a);
		tri_3_elements(a);
		print_pile(*a);
	}*/
  while (*b)
	{
		ft_push_pa(a, b);
		printf("fin push a\n");
		print_pile(*a);
		print_pile(*b);
	}
}

 void	tri_3_elements(t_pile **a)
{
	int first = (*a)->val;
	int second = (*a)->next->val;
	int third = (*a)->next->next->val;

	printf("avant tri_3 : ");
	print_pile(*a);

	if (first > second && second < third && first < third)
		ft_swap_sa(a);
	else if (first > second && second > third)
	{
		ft_swap_sa(a);
		ft_reverse_rotate_rra(a);
	}
	else if (first > second && second < third && first > third)
		ft_rotate_ra(a);
	else if (first < second && second > third && first < third)
	{
		ft_swap_sa(a);
		ft_rotate_ra(a);
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_rra(a);
}
