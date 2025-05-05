/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:50:57 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/25 01:22:01 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int s)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	if (*a != NULL && (*a)->next != NULL) 
	{
		node1 = *a;
		node2 = node1->next;
		node3 = ft_lstlast(*a);
		node3->next = node1;
		node1->prev = node3;
		node1->next = NULL;
		node2->prev = NULL;
		*a = node2;
		if (s == 1)
			write(1, "ra\n", 3);
	}
	return ;
}
