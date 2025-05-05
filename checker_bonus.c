/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:33:16 by czghoumi          #+#    #+#             */
/*   Updated: 2025/03/11 05:18:04 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	order_incorect(t_list **a, t_list **b)
{
	free_stack(*a);
	free_stack(*b);
	write(2, "Error\n", 6);
	exit (1);
}

void	check_moves(char *s, t_list **a, t_list **b)
{
	if (ft_strcmp(s, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(s, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(s, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(s, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(s, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(s, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(s, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(s, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(s, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		order_incorect(a, b);
}

void	run_opp(t_list **a, t_list **b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		check_moves(s, a, b);
		free(s);
	}
	if ((*a != NULL) && (if_sorted(*a) == 1 && *b == NULL))
		write (1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	a = creat_list_a(argc, argv);
	b = NULL;
	if (a == NULL)
		return (1); 
	run_opp(&a, &b);
	free_stack(a);
	free_stack(b);
}
