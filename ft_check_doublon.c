/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_doublon.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:06:03 by lduflot           #+#    #+#             */
/*   Updated: 2025/01/31 14:33:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//verification que TOUS les arguments soient differents les uns des autres.
void	ft_check_doublon()
{
	if (argv[i] == argv[j])
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
