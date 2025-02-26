/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/26 10:27:52 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_pile(t_pile *a)
{
	while (a)
	{
		printf("%d -> ", a->val);
		a = a->next;
	}
	printf("\n");
}

//Test fonctions pour main.
	/*printf("\n push b \n");
	ft_push_pb(&b, &a);
	print_pile(a);
	printf("\n pile b apres push \n");
	print_pile(b);
	printf("\n push b \n");
	ft_push_pa(&a, &b);
	print_pile(a);
	printf("\n pile b apres push \n");
	print_pile(b);
	printf("\n swap a \n");
	ft_swap_sa(&a);
	print_pile(a);
	printf("\n rotate a \n");
	ft_rotate_ra(&a);
	print_pile(a);
	printf("\n reverse rotate a \n");
	ft_reverse_rotate_rra(&a);
	print_pile(a);*/
