/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"

int	middle(int *midnbr, int *stack, int size)
{
	int	*tmp_stack;
	int	i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	tmp_sort(tmp_stack, size);
	*midnbr = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	rep_sort_a(t_stacks *stack, int len, int count_r)
{
	int	midnbr;
	int	nbr;

	if (check_order(stack->a, len, 0) == 1)
		return (1);
	nbr = len;
	if (len <= 3)
	{
		sort3_ab(stack, len);
		return (1);
	}
	if (!middle(&midnbr, stack->a, len))
		return (0);
	while (len != nbr / 2 + nbr % 2)
	{
		if (stack->a[0] < midnbr && (len--))
			push_b(stack, 0);
		else if (++count_r)
			rotate_a(stack, 0);
	}
	while (nbr / 2 + nbr % 2 != stack->size_a && count_r--)
		revrotate_a(stack, 0);
	return (rep_sort_a(stack, nbr / 2 + nbr % 2, 0)
		&& rep_sort_b(stack, nbr / 2, 0));
}

int	rep_sort_b(t_stacks *stack, int len, int count_r)
{
	int	midnbr;
	int	nbr;

	if (check_order(stack->b, len, 1) == 1)
		while (len--)
			push_a(stack, 0);
	if (len <= 3)
	{
		sort3_b(stack, len);
		return (1);
	}
	nbr = len;
	if (!middle(&midnbr, stack->b, len))
		return (0);
	while (len != nbr / 2)
	{
		if (stack->b[0] >= midnbr && len--)
			push_a(stack, 0);
		else if (++count_r)
			rotate_b (stack, 0);
	}
	while (nbr / 2 != stack->size_b && count_r--)
		revrotate_b(stack, 0);
	return (rep_sort_a(stack, nbr / 2 + nbr % 2, 0)
		&& rep_sort_b(stack, nbr / 2, 0));
}

int	sort(t_stacks *stack, int size)
{
	if (check_order(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack, 0);
		else if (size == 3)
			sort3_a(stack);
		else
			rep_sort_a(stack, size, 0);
	}
	return (0);
}
