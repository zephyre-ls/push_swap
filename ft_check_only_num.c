/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_only_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:20:19 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/03 16:36:11 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Verifie la presence uniquement de nombre/chiffre
//Verifie sign et space.

void	ft_check_only_num(char *str)
{
	int	i;

	i = 0;
		if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		while (str[i] != '\0')
		{
			if ( !(str[i] >= '0' && str[i] <= '9'))
			{
				write(1, "Error\n", 6);
				return;
			}
			i++;
		}
}
