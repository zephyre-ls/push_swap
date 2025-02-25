/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:13:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/25 15:38:31 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Trouver le plus grand et le plus petit nombre de ma liste chaine.
// Trouver la mediane, celle_ci devient le 1er pivot.

#include "../push_swap.h"

//regarde si l'ordre au début est croissant.
/*int	opti_look_first_croissant(t_pile *a)
{
	int	i = 0;
	while(a && a->next)
	{
		if (a->val > a->next->val)
			return i;
		a = a->next;
		i++;
	}
	return (0);
}*/
int	mediane(t_pile *a)
{
	t_pile	*tmp;
	t_pile	*tmp_little;
	t_pile	*tmp_second_little;
	t_pile	*tmp_big;
	t_pile	*tmp_second_big;
	int		tmp_pivot;
//	int	index_croissant;

/*	index_croissant = opti_look_first_croissant(a);
	while (index_croissant > 0)
	{
		a = a->next;
		index_croissant--;
	}*/
	tmp = a;
	tmp_little = a;
	tmp_second_little = a;
	tmp_big = a;
	tmp_second_big = a;
	while (tmp)
	{
    if (tmp->val < tmp_little->val)
    {
			tmp_second_little = tmp_little;
      tmp_little = tmp;
		}
    else if (tmp->val < tmp_second_little->val && tmp->val != tmp_little->val)
    {
			tmp_second_little = tmp;
		}
		if (tmp->val > tmp_big->val)
    {
			tmp_second_big = tmp_big;
			tmp_big = tmp;
    }
		else if (tmp->val > tmp_second_big->val && tmp->val != tmp_big->val)
    {
			tmp_second_big = tmp;
    }
       tmp = tmp->next;
	//printf("tmp_big: %d, tmp_little: %d\n", tmp_second_big->val, tmp_second_little->val);
	}
	tmp_pivot = (tmp_big->val - tmp_little->val);
	tmp_pivot = tmp_pivot / 2;
	tmp_pivot = (tmp_pivot + tmp_little->val);
	//printf ("le pivot est: %d\n", tmp_pivot);
	return (tmp_pivot);
}
