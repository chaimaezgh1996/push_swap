/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 07:28:12 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/11 05:23:13 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_larg_a(t_list **a, t_list **b)
{
	int	min;
	int	max;

	if (ft_lstsize(*a) <= 100)
		max = 15;
	else
		max = 35;
	min = 0;
	while (*a != NULL)
	{
		if ((*a)->index < max)
		{
			pb(a, b, 1);
			if ((*b)->index < min)
			{
				rb(b, 1);
			}
			min++;
			max++;
		}
		else
			ra(a, 1);
	}
}

void	sort_larg_b(t_list **a, t_list **b)
{
	int	largest;
	int	pos;
	int	size_b;

	largest = ft_lstsize(*b) - 1;
	while (*b != NULL)
	{
		pos = get_position(*b, largest);
		size_b = ft_lstsize(*b);
		if (pos <= size_b / 2)
		{
			while ((*b)->index != largest)
				rb(b, 1);
		}
		else
		{
			while ((*b)->index != largest)
				rrb(b, 1);
		}
		pa(a, b, 1);
		largest--;
	}
}

void	sort_large(t_list **a, t_list **b)
{
	sort_larg_a(a, b);
	sort_larg_b(a, b);
}

void	ft_sorting(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a, 1);
	if (ft_lstsize(*a) == 3)
		sorted_three(a);
	if (ft_lstsize(*a) == 4)
		sorted_foor(a, b);
	if (ft_lstsize(*a) == 5)
		sorted_five(a, b);
	if (ft_lstsize(*a) > 5)
		sort_large(a, b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = creat_list_a(argc, argv);
	b = NULL;
	if (a == NULL)
		return (1); 
	if (if_sorted(a) == 1)
		return (0);
	ft_sorting(&a, &b);
	free_stack(a);
	free_stack(b);
}
