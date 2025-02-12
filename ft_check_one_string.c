/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_one_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:00:17 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/12 09:49:26 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while(s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (nbrword);
}

char	**ft_freemallocerror(char **bigtab)
{
	size_t i;

	i = 0;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}
	free(bigtab);
	return (NULL);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);

}char	**ft_split(char const *s)
{
	int			i;
	int			j;
	int			start;
	char	**bigtab;
	
	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	bigtab = malloc(sizeof(char *) * (ft_countmot(s) + 1));
	if (bigtab == NULL)
		return (NULL);
	while(s[i])
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
