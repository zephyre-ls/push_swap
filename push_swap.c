/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:57:38 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/07 17:24:30 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verifie que les arguments sont recevables.
void	ft_check_arguments(char *str)
{
	while(str)
	{
		ft_check_one_string(*str);
		ft_check_only_num(*str);
		ft_check_max_min_int(*str);
		ft_check_doublon(*str);
	}
}
 void	push_swap(int nb);
{
	pile_a : nb;
	pile_b : NULL;


}

		
