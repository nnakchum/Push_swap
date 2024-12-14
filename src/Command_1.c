/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	swap_a(t_stacks *stack, int bonus)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return;
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (!bonus)
		ft_printf("sa\n");
}

void	swap_b(t_stacks *stack, int bonus)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
		return;
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (!bonus)
		ft_printf("sb\n");
}

void	swap_s(t_stacks *stack, int bonus)
{
	int	tmp;

	if ((stack->size_a == 0 || stack->size_a == 1 ) ||
		(stack->size_b == 0 || stack->size_b == 1))
		return;
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (!bonus)
		ft_printf("ss\n");
}

void	push_a(t_stacks *stack, int bonus)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		if (!bonus)
			ft_printf("pa\n");
	}
	else
		return ;
}

void	push_b(t_stack *stack, int bonus)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1]
		if (!bonus)
			ft_printf("pb\n");
	}
	else
		return ;
}