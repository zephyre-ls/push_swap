/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/26 10:29:18 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		error();
	if (argc == 2)
		if_argc_is_2(argv, &a);
	else
		if_argc_more_than_2(argc, argv, &a);
	/*printf("Pile A après initialisation :\n");
	print_pile(a);
	printf("Pile B apres initialisation : \n");
	print_pile(b);
	printf("Utilisation de mediane : \n");
	mediane(a);
	printf("Utilisation comparaison avec mediane : _n");
		comparaison_pivot_1(&a, &b);
	printf("Pile a: \n");
	print_pile(a);
	printf("Pile b: \n");
	print_pile(b);*/
	quick_sort(&a, &b);
	printf("Algo complet:\n");
	print_pile(a);
	//print_pile(b);
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
	freepile(a);
	freepile(b);
	return (0);
}
