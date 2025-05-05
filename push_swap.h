/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:11:21 by czghoumi          #+#    #+#             */
/*   Updated: 2025/02/27 23:34:54 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
	int				index;
}	t_list;
char	*ft_strdup(const char *s1);
t_list	*ft_lstnew(int value, int i);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstadd_back(t_list *lst, int value, int i);
typedef struct t_int
{
	unsigned int	result;
	int				is_valid;
}	t_int;
t_int	ft_atoi(const char *str);
int		ft_count(char const *s, char c);
char	*ft_strdp(const char *s1, int i, char c);
char	**rempli(char **ptr, char const *s, char c);
char	**ft_split(char const *s, char c);
int		is_whitespace(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		is_checkd(char *s);
int		check_sign(char *s);
int		check_empty_args(int argc, char **argv);
int		check_duplicate(t_list *node);
void	free_matrix(char **matrix);
void	free_stack(t_list *stack);
char	*validate_arguments(int argc, char **argv);
t_list	*populate_stack(char **result);
t_list	*creat_list_a(int argc, char **argv);
void	sa(t_list **a, int s);
void	sb(t_list **b, int s);
void	ss(t_list **a, t_list **b, int s);
void	pb(t_list **a, t_list **b, int s);
void	pa(t_list **a, t_list **b, int s);
void	ra(t_list **a, int s);
void	rb(t_list **b, int s);
void	rr(t_list **b, t_list **a, int s);
void	rrb(t_list **b, int s);
void	rra(t_list **a, int s);
void	rrr(t_list **b, t_list **a, int s);
int		ft_lstsize(t_list *lst);
void	modifie_index_orginised(t_list *a);
void	modifie_index_to_min_one(t_list *a);
int		if_sorted(t_list *a);
int		is_the_smallest(t_list *a);
int		if_sorted_in_list(t_list *a);
void	sorted_three(t_list **a);
void	sorted_foor(t_list **a, t_list **b);
void	sorted_five(t_list **a, t_list **b);
void	ft_sorting(t_list **a, t_list **b);
void	sort_larg_b(t_list **a, t_list **b);
void	sort_larg_a(t_list **a, t_list **b);
int		get_position(t_list *lst, int num);
int		get_small_index(t_list *a);
void	pouch_small_to_b_five(t_list **a, t_list **b);
void	pouch_small_to_b_foor(t_list **a, t_list **b);

#endif
