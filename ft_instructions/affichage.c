/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 15:01:18 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_instruction(void)
{
	static	int count_instruction = 0;
	count_instruction++;
	printf("Nbr d'instructions:%d\n", count_instruction);
}

void	 print_pile(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
  while (tmp != NULL)
  {
		ft_putnbr_fd(tmp->val, 1);
		ft_putstr_fd(" -> ", 1);
		tmp = tmp->next;
	}
}

