/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:05 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/12 16:29:23 by lduflot          ###   ########.fr       */
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


void count_instruction(char *instruction)
{
	static char last_instruction[500000] = "";
  static int count_instruction = 0;

  if ((ft_strcmp(last_instruction, "ra") == 0 && ft_strcmp(instruction, "rb") == 0) ||
    (ft_strcmp(last_instruction, "rb") == 0 && ft_strcmp(instruction, "ra") == 0))
  {
    printf("rr\n");
    count_instruction++;  
	}
  else
  {
    printf("%s\n", instruction);  // Affiche l'instruction individuelle
    count_instruction++;
	}
  ft_strcpy(last_instruction, instruction);
  printf("Nbr d'instructions: %d\n", count_instruction);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;
	const char	*ss1;
	const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	while ((ss1[i] != '\0' && ss2[i] != '\0') && (ss1[i] == ss2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	sizesrc;

	sizesrc = 0;
	while (src[sizesrc] != '\0')
	{
		sizesrc++;
	}
	if (size == 0)
	{
		return (sizesrc);
	}
	i = 0;
	while (src[i] != '\0' && i < (size -1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sizesrc);
}
