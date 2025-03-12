/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 22:21:17 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	count_instruction(void)
{
	static	int count_instruction = 0;
	count_instruction++;
	printf("Nbr d'instructions:%d\n", count_instruction);
}*/

void	 print_pile(t_pile *a)
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

/*void	count_instruction(char *instruction)
{
	static char last_instruction[4] = "";
	static int count_instruction = 0;

	if ((ft_strcmp(last_instruction, "ra") == 0 && ft_strcmp(instruction, "rb") == 0) ||
		(ft_strcmp(last_instruction, "rb") == 0 && ft_strcmp(instruction, "ra") == 0))
	{
		ft_putendl_fd("rr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else if ((ft_strcmp(last_instruction, "rra") == 0 && ft_strcmp(instruction, "rrb") == 0) ||
		(ft_strcmp(last_instruction, "rrb") == 0 && ft_strcmp(instruction, "rra") == 0))
	{
		ft_putendl_fd("rrr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else
	{
		ft_putendl_fd(instruction, 1);
	//	printf("%s\n", instruction);
		count_instruction++;
		ft_strlcpy(last_instruction, instruction, sizeof(last_instruction));
	}
	//printf("Nbr d'instructions: %d\n", count_instruction);
}*/

void	count_instruction(char *instruction)
{
	static char last_instruction[4] = "";
	static int count_instruction = 0;

	if ((ft_strcmp(last_instruction, "ra") == 0 && ft_strcmp(instruction, "rb") == 0) ||
		(ft_strcmp(last_instruction, "rb") == 0 && ft_strcmp(instruction, "ra") == 0))
	{
		ft_putendl_fd("rr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else if ((ft_strcmp(last_instruction, "rra") == 0 && ft_strcmp(instruction, "rrb") == 0) ||
		(ft_strcmp(last_instruction, "rrb") == 0 && ft_strcmp(instruction, "rra") == 0))
	{
		ft_putendl_fd("rrr", 1);
		count_instruction++;
		last_instruction[0] = '\0';
	}
	else
	{
		ft_putendl_fd(instruction, 1);
		count_instruction++;
		if (ft_strcmp(instruction, "ra") == 0 || ft_strcmp(instruction, "rb") == 0 ||
			ft_strcmp(instruction, "rra") == 0 || ft_strcmp(instruction, "rrb") == 0)
		{
			ft_strlcpy(last_instruction, instruction, sizeof(last_instruction));
		}
		else
			last_instruction[0] = '\0';
	}
//	printf("Nbr d'instructions: %d\n", count_instruction);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
