/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argument_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:44:57 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/07 10:59:34 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cas ou l'useur met une serie d'argument dans "" permet la prise en compte.


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
	dest[j] = '\0';
	return (dest);
}

int	ft_countmot(char const *s, char c)
{
	int	i;
	int	nbrword;

	i = 0;
	nbrword = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' '|| s[i] == '\t')
			i++;
		if (s[i] != '\0')
		{
			nbrword++;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
				i++;
		}
	}
	return (nbrword);
}

char	**ft_freemallocerror(char **bigtab)
{
	size_t	i;

	i = 0;
	while (bigtab[i])
	{
		free(bigtab[i]);
		i++;
	}

	free(bigtab);
	return (NULL);
}

int	ft_start(char const *s, int *i, char c)
{
	int	start;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (start);
}

char	**ft_split(char const *s, char c)
{
	char	**bigtab;
	int		i;
	int		j;
	int		start;

	bigtab = malloc(sizeof(char *) * (ft_countmot(s, c) + 1));
	if (s == NULL || bigtab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		start = ft_start(s, &i, ' ');
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
