/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:10 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/07 07:44:36 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstadd_back(t_list *lst, int value, int i)
{
	t_list	*l;
	t_list	*new_node;

	if (lst == NULL)
		return (0);
	l = ft_lstlast(lst);
	new_node = ft_lstnew(value, i);
	if (new_node == NULL)
		return (0);
	l->next = new_node;
	new_node->prev = l;
	return (1);
}
