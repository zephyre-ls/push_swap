/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_one_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:00:17 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/14 11:37:29 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_countmot(char const *s)
{
	int	i;
	int	nbrword;

	i = 0;
	nbrword = 0;
	while (s[i])
	{
		while ((s[i] && ft_isspace(s[i])))
			i++;
		if (s[i])
			nbrword++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (nbrword);
}

void	ft_free_split(char **bigtab)
{
	int	i;

	i = 0;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
}

int	ft_start(char const *s, int *i)
{
	int	start;

	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	start = *i;
	while (s[*i] && !ft_isspace(s[*i]))
		(*i)++;
	return (start);
}

char	**ft_split(char const *s)
{
	int		i;
	int		j;
	int		start;
	char	**bigtab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	bigtab = malloc(sizeof(char *) * (ft_countmot(s) + 1));
	if (bigtab == NULL)
		return (NULL);
	while (s[i])
	{
		start = ft_start(s, &i);
		if (i > start)
		{
			bigtab[j] = ft_substr(s, start, i - start);
			if (bigtab[j] == NULL)
				return (ft_freemallocerror(bigtab));
			j++;
		}
	}
	bigtab[j] = NULL;
	return (bigtab);
}
