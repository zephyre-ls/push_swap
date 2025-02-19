/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/19 20:10:42 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i = 1;
	char	**arg_split;
	t_pile *a = NULL;
	t_pile *b = NULL;

	if (argc < 2)
		error();
	if (argc == 2)
	{
		arg_split = ft_split(argv[1]);
		if (arg_split == NULL || arg_split[0] == NULL || arg_split[1] == NULL)
			error();
		i = 0;
		while (arg_split[i])
		{
			ft_check_only_num(arg_split[i]);
			ft_check_max_min_int(arg_split[i]);
			i++;
		}
		ft_check_doublon(i, arg_split);
		ft_check_tri(arg_split);
		init_pile(&a, i, arg_split);
	}
	else
	{
		while(i < argc)
		{
			ft_check_only_num(argv[i]);
			ft_check_max_min_int(argv[i]);
			i++;
		}
		ft_check_tri(argv);
		ft_check_doublon(argc, argv);
		init_pile(&a, argc, argv);
	}
// Affichage de la pile A après l'initialisation
	printf("Pile A après initialisation :\n");
	print_pile(a);
	printf("Pile B apres initialisation : \n");
	print_pile(b);

	// TEST DES FONCTIONS
	printf("\n push b \n");
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
	//ft_swap_sa(&a);
	print_pile(a);

	printf("\n rotate a \n");
	ft_rotate_ra(&a);
	print_pile(a);

	printf("\n reverse rotate a \n");
	ft_reverse_rotate_rra(&a);
	print_pile(a);

	// Libération de la mémoire
	freepile(a);
	freepile(b);

	return (0);
}
