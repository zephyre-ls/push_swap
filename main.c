/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/03 09:13:25 by lduflot          ###   ########.fr       */
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
	freepile(a);
	freepile(b);
	return (0);
}
