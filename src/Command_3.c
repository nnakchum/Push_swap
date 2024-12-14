/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	revrotate_a(t_stacks *stack, int bonus)
{
	int	tmp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	if (!bonus)
		ft_printf("rra\n");
}

void	revrotate_b(t_stacks *stack, int bonus)
{
	int	tmp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i - 1] = stack->b[i];
		i--;
	}
	stack->b[i] = tmp;
	if (!bonus)
		ft_printf("rrb\n");
}

vvoid	revrotate_r(t_stacks *stack, int bonus)
{
	int	tmp;
	int	i;

	if ((stack->size_a == 0 || stack->size_a == 1)
		|| (stack->size_b == 0 || stack->size_b == 1))
		return ;
	i = stack->size_a - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i - 1] = stack->a[i];
		i--;
	}
	stack->a[i] = tmp;
	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i - 1] = stack->b[i];
		i--;
	}
	stack->b[i] = tmp;
	if (!bonus)
		ft_printf("rrr\n");
}
