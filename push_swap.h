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
