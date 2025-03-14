/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:08:22 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_pile(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
	while (tmp)
	{
		ft_putnbr_fd(tmp->val, 1);
		ft_putstr_fd(" -> ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	count_instruction(char *instruction)
{
	static char	last_instruction[3] = "";
	static int	count_instruction = 0;

	if ((ft_strcmp(last_instruction, "ra") == 0
			&& ft_strcmp(instruction, "rb") == 0)
		|| (ft_strcmp(last_instruction, "rb") == 0
			&& ft_strcmp(instruction, "ra") == 0))
	{
		ft_putendl_fd("rr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else if ((ft_strcmp(last_instruction, "rra") == 0
			&& ft_strcmp(instruction, "rrb") == 0)
		|| (ft_strcmp(last_instruction, "rrb") == 0
			&& ft_strcmp(instruction, "rra") == 0))
	{
		ft_putendl_fd("rrr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else
		ft_putendl_fd(instruction, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
