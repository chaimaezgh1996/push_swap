/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 07:28:12 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/25 01:24:06 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_numbers_in_range(t_list *lst, int min, int max)
{
	while (lst)
	{
		if (lst->index >= min && lst->index <= max)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	get_position(t_list *lst, int num)
{
	int	pos; 

	pos = 0;
	while (lst)
	{
		if (lst->index == num)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}
