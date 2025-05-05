/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:50:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/02 22:42:32 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (*b != NULL && (*b)->next != NULL) 
	{
		node1 = *b;
		node2 = node1->next;
		node3 = ft_lstlast(*b);
		node3->next = node1;
		node1->prev = node3;
		node1->next = NULL;
		node2->prev = NULL;
		*b = node2;
		if (s == 1)
			write(1, "rb\n", 3);
	}
	return ;
}

void	rr(t_list **b, t_list **a, int s)
{
	if ((*b != NULL && (*b)->next != NULL) 
		|| (*a != NULL && (*a)->next != NULL))
	{
		if (*b != NULL && (*b)->next != NULL) 
			rb(b, 0);
		if (*a != NULL && (*a)->next != NULL) 
			ra(a, 0);
		if (s == 1)
			write(1, "rr\n", 3);
	}
	return ;
}

void	rra(t_list **a, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (*a != NULL && (*a)->next != NULL) 
	{
		node1 = *a;
		node3 = ft_lstlast(*a);
		node2 = node3->prev;
		node3->prev = NULL;
		node3->next = node1;
		node1->prev = node3;
		node2->next = NULL;
		*a = node3;
		if (s == 1)
			write(1, "rra\n", 4);
	}
	return ;
}

void	rrb(t_list **b, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (*b != NULL && (*b)->next != NULL) 
	{
		node1 = ft_lstlast(*b);
		node2 = *b; 
		node3 = node1->prev;
		node3->next = NULL;
		node1->next = node2;
		node2->prev = node1;
		node1->prev = NULL;
		*b = node1;
		if (s == 1)
			write(1, "rrb\n", 4);
	}
	return ;
}

void	rrr(t_list **b, t_list **a, int s)
{
	if ((*b != NULL && (*b)->next != NULL) 
		|| (*a != NULL && (*a)->next != NULL))
	{
		if (*b != NULL && (*b)->next != NULL) 
			rrb(b, 0);
		if (*a != NULL && (*a)->next != NULL) 
			rra(a, 0);
		if (s == 1)
			write(1, "rrr\n", 4);
	}
	return ;
}
