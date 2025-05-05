/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_to_movs1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:43:03 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/24 23:00:42 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_sorted_in_list(t_list *a)
{
	t_list	*n1;

	n1 = a->next;
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

void	sorted_three(t_list **a)
{
	t_list	*ss;
	t_list	*n1;

	if (if_sorted_in_list(*a))
		return ;
	ss = *a;
	if (is_the_smallest(*a) == 0)
		return (sa(a, 1), ra(a, 1));
	n1 = ss->next;
	if (is_the_smallest(*a) == 1)
	{
		if (ss->index > n1->next->index)
			return (ra(a, 1));
		return (sa(a, 1));
	}
	if (n1->index > ss->index)
		return (rra(a, 1));
	sa(a, 1);
	rra(a, 1);
}

void	sorted_foor(t_list **a, t_list **b)
{
	int		i;
	t_list	*n1;

	if (if_sorted_in_list(*a))
		return ;
	pb(a, b, 1);
	sorted_three(a);
	n1 = *a;
	i = 0;
	while (n1 && (*b)->index > n1->index)
	{
		n1 = n1->next;
		i++;
	}
	if (i == 0)
		return (pa(a, b, 1));
	if (i == 1)
		return (ra(a, 1), pa(a, b, 1), rra(a, 1));
	if (i == 2)
		return (rra(a, 1), pa(a, b, 1), ra(a, 1), ra(a, 1));
	pa(a, b, 1);
	ra(a, 1);
}

void	sorted_five(t_list **a, t_list **b)
{
	int		i;
	t_list	*n1;

	if (if_sorted_in_list(*a) == 1)
		return ;
	pb(a, b, 1);
	i = 0;
	sorted_foor(a, b);
	n1 = *a;
	while (n1 != NULL && (*b)->index > n1->index)
	{
		n1 = n1->next;
		i++;
	}
	if (i == 0)
		pa(a, b, 1);
	if (i == 1)
		return (ra(a, 1), pa(a, b, 1), rra(a, 1));
	if (i == 2)
		return (ra(a, 1), ra(a, 1), pa(a, b, 1), rra(a, 1), rra(a, 1));
	if (i == 3)
		return (rra(a, 1), pa(a, b, 1), ra(a, 1), ra(a, 1));
	if (i == 4)
		return (pa(a, b, 1), ra(a, 1));
}
