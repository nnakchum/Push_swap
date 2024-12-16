/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"

void	free_error(t_stacks *stack, int check)
{
	free(stack->a);
	free(stack->b);
	if (check)
		ft_printf("Error\n");
	exit(1);
}

void	exec_command(t_stacks *stack, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		swap_a(stack, 1);
	else if (!ft_strcmp(command, "sb\n"))
		swap_b(stack, 1);
	else if (!ft_strcmp(command, "ss\n"))
		swap_s(stack, 1);
	else if (!ft_strcmp(command, "ra\n"))
		rotate_a(stack, 1);
	else if (!ft_strcmp(command, "rb\n"))
		rotate_b(stack, 1);
	else if (!ft_strcmp(command, "rr\n"))
		rotate_r(stack, 1);
	else if (!ft_strcmp(command, "rra\n"))
		revrotate_a(stack, 1);
	else if (!ft_strcmp(command, "rrb\n"))
		revrotate_b(stack, 1);
	else if (!ft_strcmp(command, "rrr\n"))
		revrotate_r(stack, 1);
	else if (!ft_strcmp(command, "pa\n"))
		push_a(stack, 1);
	else if (!ft_strcmp(command, "pb\n"))
		push_b(stack, 1);
	else
		free_error(stack, 1);
}

void	read_stdin(t_stacks *stack)
{
	char		*command;

	command = get_next_line(0);
	while (command)
	{
		exec_command(stack, command);
		free(command);
		command = get_next_line(0);
	}
	if (check_order(stack->a, stack->size_a, 0) && stack->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("K0\n");
	free_error(stack, 0);
}

int	*c_errors(char **av)
{
	int	*a;
	int	size;
	int	i;

	i = -1;
	size = ps_strlen(av);
	a = malloc(size * sizeof(int));
	while (++i < size)
		a[i] = ps_atoi(av[i], a);
	check_double(a, size);
	return (a);
}

int	main(int ac, char **av)
{
	t_stacks	stack;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		stack.a = c_errors(av);
		stack.size_a = ps_strlen(av);
		stack.b = malloc(stack.size_a * sizeof(int));
		if (!stack.b)
		{
			free(stack.a);
			return (0);
		}
		stack.size_b = 0;
		read_stdin(&stack);
	}
	return (0);
}
