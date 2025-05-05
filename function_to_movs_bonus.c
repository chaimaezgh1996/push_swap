/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_to_movs_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:32:13 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/03 02:41:15 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	modifie_index_to_min_one(t_list *a)
{
	t_list	*node1;

	if (a != NULL)
	{
		node1 = a;
		while (node1 != NULL)
		{
			node1->index = -1;
			node1 = node1->next;
		}
	}
	return ;
}

void	modifie_index_orginised(t_list *a)
{
	t_list	*n1;
	t_list	*n2;
	int		i;

	i = 0;
	modifie_index_to_min_one(a);
	while (i <= ft_lstsize(a))
	{
		n1 = NULL;
		n2 = a;
		while (n2 != NULL)
		{
			if (n2->index == -1 && (n1 == NULL || n2->content < n1->content))
				n1 = n2;
			n2 = n2->next;
		}
		if (n1 != NULL)
			n1->index = i;
		i++;
	}
}

int	if_sorted(t_list *a)
{
	t_list	*n1;

	n1 = a->next;
	if (!a)
		return (0);
	modifie_index_orginised(a);
	while (a != NULL && n1 != NULL)
	{
		if (a->index < n1->index)
		{
			a = a->next;
			n1 = n1->next;
		}
		else
			return (0);
	}
	return (1);
}

int	is_the_smallest(t_list *a)
{
	t_list	*n1;
	int		minindex;
	int		pos;
	int		minpos;

	n1 = a->next;
	minindex = a->index;
	pos = 0;
	minpos = 0;
	while (n1 != NULL)
	{
		if (n1->index < minindex)
		{
			minindex = n1->index;
			minpos = pos + 1; 
		}
		n1 = n1->next;
		pos++;
	}
	if (minpos == 0)
		return (0); 
	else if (minpos == pos)
		return (2); 
	else
		return (1);
}
