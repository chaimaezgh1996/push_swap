/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:10 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/27 23:49:09 by czghoumi         ###   ########.fr       */
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

void	sorted_foor(t_list **a, t_list **b)
{
	if (if_sorted_in_list(*a))
		return ;
	pouch_small_to_b_foor(a, b);
	sorted_three(a);
	pa(a, b, 1);
}

void	sorted_five(t_list **a, t_list **b)
{
	if (if_sorted_in_list(*a) == 1)
		return ;
	pouch_small_to_b_five(a, b);
	sorted_foor(a, b);
	pa(a, b, 1);
}
