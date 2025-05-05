/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:10 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/07 06:50:25 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

char	*ft_strdp(const char *s1, int i, char c)
{
	char	*ptr;
	int		len;
	int		j;

	len = 0;
	j = 0;
	while (s1[i + len] != '\0' && s1[i + len] != c)
		len++;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (j < len)
	{
		ptr[j] = s1[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**rempli(char **ptr, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ptr[j] = ft_strdp(s, i, c);
			if (ptr[j] == NULL)
			{
				while (j > 0)
					free(ptr[--j]);
				return (free(ptr), (NULL));
			}
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_count(s, c);
	ptr = malloc ((count + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	return (rempli(ptr, s, c));
}

int	is_whitespace(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || (s[i] <= 9 && s[i] >= 13))
			i++;
		else
			return (1);
	}
	return (0);
}
