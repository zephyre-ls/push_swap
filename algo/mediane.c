/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:13:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/11 19:24:45 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Trouver le plus grand et le plus petit nombre de ma liste chaine.
// Trouver la mediane, celle_ci devient le 1er pivot.

#include "../push_swap.h"

// Recherche du plus grand/petit nombre de ma pile.a
// Mediane = 1er pivot.
int	mediane(t_pile *a)
{
	t_pile	*tmp;
	t_pile	*tmp_little;
	t_pile	*tmp_big;
	int		tmp_pivot;

	tmp = a;
	tmp_little = a;
	tmp_big = a;
	while (tmp)
	{
		if (tmp->val > tmp_big->val)
			tmp_big = tmp;
		else if (tmp->val < tmp_little->val)
			tmp_little = tmp;
		tmp = tmp->next;
	}
	tmp_pivot = (tmp_big->val - tmp_little->val);
	tmp_pivot = tmp_pivot / 2;
	tmp_pivot = (tmp_pivot + tmp_little->val);
//	printf("le pivot est: %d\n", tmp_pivot);
	return (tmp_pivot);
}

//quand 11 element dans .a le pivot devient le 3eme plus grand nombre de la liste
// permet d eviter le cas ou la mediane est plus grande que le 3eme plus grand element
int	pivot_10(t_pile *a)
{
	t_pile *tmp_a;
	int	first;
	int	second;
	int	third_pivot;

	tmp_a = a;
	first = 0;
	second = 0;
  while (tmp_a)
  {
		if (tmp_a->val > first)
    {
      third_pivot = second;
      second = first;
      first = tmp_a->val;
    }
    else if (tmp_a->val > second)
    {
      third_pivot = second;
      second = tmp_a->val;
    }
    else if (tmp_a->val > third_pivot)
			third_pivot = tmp_a->val;
    tmp_a = tmp_a->next;
    }
		return third_pivot ;
}
