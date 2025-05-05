/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:50:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/25 01:21:57 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (ft_lstsize(*a) > 1)
	{
		node1 = *a;
		node2 = node1->next;
		node3 = node2->next;
		node2->next = node1;
		node2->prev = NULL;
		node1->prev = node2;
		node1->next = node3;
		if (node3)
			node3->prev = node1;
		*a = node2;
		if (s == 1)
			write(1, "sa\n", 3);
	}
	return ;
}

void	sb(t_list **b, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (ft_lstsize(*b) > 1)
	{
		node1 = *b;
		node2 = node1->next;
		node3 = node2->next;
		node2->next = node1;
		node2->prev = NULL;
		node1->prev = node2;
		node1->next = node3;
		if (node3)
			node3->prev = node1;
		*b = node2;
		if (s == 1)
			write(1, "sa\n", 3);
	}
	return ;
}

void	ss(t_list **a, t_list **b, int s)
{
	if (ft_lstsize(*a) > 1)
		sa(a, 0);
	if (ft_lstsize(*b) > 1)
		sb(b, 0);
	if ((ft_lstsize(*a) > 1 || ft_lstsize(*b) > 1) && s == 1)
		write(1, "ss\n", 3);
	return ;
}

void	pa(t_list **a, t_list **b, int s)
{
	t_list	*node1;

	if (*b == NULL) 
		return ;
	node1 = *b;
	*b = node1->next;
	if (*b != NULL) 
		(*b)->prev = NULL;
	node1->next = *a;
	if (*a != NULL) 
		(*a)->prev = node1;
	*a = node1;
	if (s == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int s)
{
	t_list	*node1;

	if (*a == NULL) 
		return ;
	node1 = *a;
	*a = node1->next;
	if (*a != NULL) 
		(*a)->prev = NULL;
	node1->next = *b;
	if (*b != NULL) 
		(*b)->prev = node1;
	*b = node1;
	if (s == 1)
		write(1, "pb\n", 3);
}
