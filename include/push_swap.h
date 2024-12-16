/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 00:15:30 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/14 04:26:30 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

void	swap_a(t_stacks *stack, int bonus);
void	swap_b(t_stacks *stack, int bonus);
void	swap_s(t_stacks *stack, int bonus);
void	push_a(t_stacks *stack, int bonus);
void	push_b(t_stacks *stack, int bonus);
void	rotate_a(t_stacks *stack, int bonus);
void	rotate_b(t_stacks *stack, int bonus);
void	rotate_r(t_stacks *stack, int bonus);
void	revrotate_a(t_stacks *stack, int bonus);
void	revrotate_b(t_stacks *stack, int bonus);
void	revrotate_r(t_stacks *stack, int bonus);
int		ps_atoi(char *str, int *stack);
int		ps_strlen(char **av);
int		check_order(int *stack, int size, int order);
void	check_double(int *stack, int size);
void	error_found(int *stack);
int		ft_push(t_stacks *stack, int len, int push);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *s);
int		middle(int *midnbr, int *stack, int size);
int		rep_sort_a(t_stacks *stack, int len, int count_r);
int		rep_sort_b(t_stacks *stack, int len, int count_r);
int		sort(t_stacks *stack, int size);
void	tmp_sort(int *tmp_stack, int size);
void	sort3_a(t_stacks *stack);
int		sort3_b(t_stacks *stack, int len);
void	sort3_ab(t_stacks *stack, int len);
void	push_swap(char **av);
void	read_stdin(t_stacks *stack);
int		*c_errors(char **av);
void	exec_command(t_stacks *stack, char *instruction);
void	free_error(t_stacks *stack, int check);
#endif