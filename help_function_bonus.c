/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:16 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/26 20:03:23 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*populate_stack(char **result)
{
	int		i;
	t_list	*node;
	int		j;

	i = 0;
	node = ft_lstnew(ft_atoi(result[0]).result, i);
	if (node == NULL)
		return (free_matrix(result), NULL);
	j = 1;
	i++;
	while (result[j])
	{
		if (ft_lstadd_back(node, ft_atoi(result[j]).result, i) == 0)
			return (free_stack(node), NULL);
		j++;
		i++;
	}
	return (node);
}

char	*validate_arguments(int argc, char **argv)
{
	int		i;
	char	*s;

	if (argc < 2)
		return (NULL);
	if (check_empty_args(argc, argv) == 0)
		return (NULL);
	s = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		s = ft_strjoin(s, argv[i]);
		i++;
	}
	if (is_checkd(s) == 0 || check_sign(s) == 0)
		return (free(s), NULL);
	return (s);
}

int	check_duplicate(t_list *node)
{
	int		ss;
	t_list	*kk;

	while (node != NULL)
	{
		ss = node->content;
		node = node->next;
		kk = node;
		while (kk != NULL)
		{
			if (ss != kk->content)
				kk = kk->next;
			else
				return (0);
		}
	}
	return (1);
}

t_list	*ft_lstnew(int value, int i)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = value;
	head->next = NULL;
	head->prev = NULL;
	head->index = i;
	return (head);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_strlen((char *)s1) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
