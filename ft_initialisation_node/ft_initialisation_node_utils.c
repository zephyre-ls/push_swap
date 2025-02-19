/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation_node_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:55:32 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/19 20:41:03 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ajoute new debut lst
void	*ft_lstadd_front(t_pile **lst, t_pile *new)
{
	new ->next = *lst;
	*lst = new;
	return(NULL);
}
//ajoute new fin lst
void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile *tmp;

	tmp = *lst;
	if(*lst == NULL)
	{
		*lst = new;
		return;
	}
	while(tmp->next && tmp != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
//taille de la liste
int	ft_lstsize(t_pile **lst)
{
	int	i;

	i = 0;
	while(*lst != NULL)
	{
		(*lst) = (*lst)->next;
		i++;
	}
	return(i);
}
//ajout un new noeud
t_pile	*ft_lstnew(int val)
{
	t_pile	*new;

	new = (malloc(sizeof(t_pile)));
	if(new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->val = val;
	new->next = NULL;
	return (new);
}
//affiche le dernier noeud de la liste avant NULL
t_pile	*ft_lstlast(t_pile *lst)
{
	int	i;

	i = 0;
	if(lst != NULL)
	{
		while(lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
		return(lst);
	}
	return (NULL);
}

void	print_pile(t_pile *a)
{
	while(a)
	{
		printf("%d -> ", a->val);
		a = a->next;
	}
	printf("\n");
}

