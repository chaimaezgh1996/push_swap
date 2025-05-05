/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_to_movs_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 05:43:03 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/27 23:48:51 by czghoumi         ###   ########.fr       */
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

int	get_small_index(t_list *a)
{
	int	min;

	min = a->index;
	while (a != NULL)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}

void	pouch_small_to_b_foor(t_list **a, t_list **b)
{
	int	s;
	int	l;

	l = get_small_index(*a);
	s = get_position(*a, l);
	if (s == 0)
		pb(a, b, 1);
	if (s == 1)
		return (sa(a, 1), pb(a, b, 1));
	if (s == 2)
		return (ra(a, 1), ra(a, 1), pb(a, b, 1));
	if (s == 3)
		return (rra(a, 1), pb(a, b, 1));
}

void	pouch_small_to_b_five(t_list **a, t_list **b)
{
	int	s;
	int	l;

	l = get_small_index(*a);
	s = get_position(*a, l);
	if (s == 0)
		pb(a, b, 1);
	if (s == 1)
		return (sa(a, 1), pb(a, b, 1));
	if (s == 2)
		return (ra(a, 1), ra(a, 1), pb(a, b, 1));
	if (s == 3)
		return (rra(a, 1), rra(a, 1), pb(a, b, 1));
	if (s == 4)
		return (rra(a, 1), pb(a, b, 1));
}
