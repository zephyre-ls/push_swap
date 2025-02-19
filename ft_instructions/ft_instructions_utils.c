/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/19 18:43:29 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_pile(t_pile *a)
{
	while(a)
	{
		printf("%d -> ", a->val);
		a = a->next;
	}
	printf("\n");
}

t_pile	*ft_lstbefore_last(t_pile *lst)
{
	if (!lst || !(lst->next))
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

