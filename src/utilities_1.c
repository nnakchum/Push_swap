/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"

int	ft_push(t_stacks *stack, int len, int push)
{
	if (push == 0)
		push_b(stack, 0);
	else
		push_a(stack, 0);
	len--;
	return (len);
}

int	ps_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

int	check_order(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_double(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				error_found(stack);
			j++;
		}
		i++;
	}
}

void	error_found(int *stack)
{
	free(stack);
	ft_printf("Error\n");
	exit (1);
}
