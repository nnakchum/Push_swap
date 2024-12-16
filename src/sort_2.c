/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"

void	tmp_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort3_a(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] < stack->a[2])
		swap_a(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack, 0);
		revrotate_a(stack, 0);
	}
	if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] < stack->a[2])
		rotate_a(stack, 0);
	if (stack->a[0] < stack->a[1] && stack->a[0] < stack->a[2]
		&& stack->a[1] > stack->a[2])
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2]
		&& stack->a[1] > stack->a[2])
		revrotate_a(stack, 0);
}

int	sort3_b(t_stacks *stack, int len)
{
	if (len == 1)
		push_a(stack, 0);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack, 0);
		while (len--)
			push_a(stack, 0);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack, 0);
		}
	}
	return (0);
}

void	sort3_ab(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort3_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack, 0);
			else if (len++)
				push_a(stack, 0);
		}
	}
}
