/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/07 17:58:55 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ajoute new au debut de la list lst
void	ft_lstadd_front(t_pile **lst, piles *new)
{
	new ->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_pile **lst, piles *new)
{
	if(*lst == NULL)
	{
		*lst = new;
		return;
	}
	while((*lst)->next && *lst != NULL)
		*lst = (*lst)->next;
	(*lst)->next = new;
}

int	ft_lstsize(t_pile **lst)
{
	int	i;

	i = 0;
	while((*lst)->next && *lst != NULL)
	{
		*lst = (*lst)->next;
		i++;
	}
	return(i);
}

piles	ft_lstlast(t_pile **lst)
{
	int	i;

	i = 0;
	if(*lst != NULL)
	{
		while((*lst)->next != NULL)
		{	
			*lst = (*lst)->next;
			i++;
		}
		return(*lst);
	}
}
