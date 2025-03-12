/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:38:54 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 14:55:44 by lduflot          ###   ########.fr       */
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
	quick_sort(&a, &b);
	printf("Pile trie:\n");
	print_pile(a);
	freepile(a);
	freepile(b);
	return (0);
}
