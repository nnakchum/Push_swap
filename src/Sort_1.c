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

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int mediane(int *midnbr, int *stack, int size)
{
    int *tmp_stack;
    int i;

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

