/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:31:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/06 16:30:02 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ajoute new au debut de la list lst
void	ft_lstadd_front(t_list *lst, t_list *new)
{
	new ->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if(lst == NULL)
	{
		lst = new;
		return;
	}
	while(lst->next && lst != NULL)
		lst = lst->next
	lst->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while(lst->next && lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return(i);
}


