/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:17:16 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/27 23:48:14 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

t_int	ft_atoi(const char *str)
{
	t_int				total;
	int					sign;
	int					i;

	i = 0;
	sign = 1;
	total.result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+') 
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total.result = (total.result * 10) + (str[i] - '0');
		if ((total.result > 2147483648 && sign == -1)
			|| (total.result > 2147483647 && sign == 1))
			return (total.is_valid = 0, total);
		i++;
	}
	total.result = total.result * sign;
	return (total.is_valid = 1, total);
}

int	check_empty_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_whitespace(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
