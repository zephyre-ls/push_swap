/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_only_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:19 by lduflot           #+#    #+#             */
/*   Updated: 2025/01/30 16:53:33 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verifie la presence uniquement de nombre/chiffre
//Verifie sign et space.
void	ft_check_only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! (str[i] >= '0' && str[i] <= '9') || str[i] != ' '
			|| str[i] != '+' || str[i] != '-')
		{
			write(1, "Error\n", 6)
			return (0);
		}
		i++;
	}
}
