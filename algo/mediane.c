/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:13:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/22 09:17:07 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Trouver le plus grand et le plus petit nombre de ma liste chaine.
// Faire une mediane
// Soit choisir un des pivots en fonctions de la mediane soit la mediane devient le pivot ? 

#include "../push_swap.h"

void mediane(t_pile *a)
{
	t_pile *tmp;
	t_pile	*tmp_little;
	t_pile	*tmp_big;

	tmp = a;
	tmp_little = a;
	tmp_big = a;
	while(tmp)
	{
		if(tmp->val > tmp_big->val)
			tmp_big = tmp;
		else if (tmp->val < tmp_little->val)
			tmp_little = tmp;
		tmp = tmp->next;
		printf("tmp_big: %d, tmp_little: %d\n", tmp_big->val, tmp_little->val);
	}
	// faire la mediane de tmp_little - tmp_big;
		int	tmp_pivot;
	
		tmp_pivot = (tmp_big->val - tmp_little->val);
		tmp_pivot = tmp_pivot / 2;
		tmp_pivot = (tmp_pivot + tmp_little->val);
		printf("le pivot est: %d\n", tmp_pivot);
}
