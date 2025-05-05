/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:10 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/13 05:43:14 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	free(s1);
	ptr[i] = ' ';
	j = -1;
	while (s2[++j])
		ptr[++i] = s2[j];
	ptr[++i] = '\0';
	return (ptr);
}

int	is_checkd(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && (s[i] < '0' || s[i] > '9') 
			&& s[i] != '-' && s[i] != '+')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[0] == '-' || s[0] == '+')
			i++;
		if (s[i] == '-' || s[i] == '+')
		{
			if ((s[i + 1] < '0' || s[i + 1] > '9') || s[i - 1] != ' ')
				return (0);
		}
		i++;
	}
	if ((s[0] == '-' || s[0] == '+') && (s[1] < '0' || s[1] > '9'))
		return (0);
	return (1);
}

t_list	*creat_list_a(int argc, char **argv)
{
	t_list	*a;
	char	*s;
	char	**result;
	int		i;

	a = NULL;
	s = validate_arguments(argc, argv);
	if (!s)
		return (write(2, "Error\n", 6), NULL);
	result = ft_split(s, ' ');
	free(s);
	if (!result)
		return (write(2, "Error\n", 6), NULL);
	i = -1;
	while (result[++i])
		if (ft_atoi(result[i]).is_valid == 0)
			return (free_matrix(result), write(2, "Error\n", 6), NULL);
	a = populate_stack(result);
	free_matrix(result);
	if (check_duplicate(a) == 0)
		return (free_stack(a), a = NULL, write(2, "Error\n", 6), a);
	return (a);
}
