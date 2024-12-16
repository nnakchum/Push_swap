/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/12/06 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include <limits.h>

void	check_digit(char c, int *stack)
{
	if (c < '0' || c > '9')
		error_found(stack);
}

void	check_overflow(unsigned long nbr, int sign, int *stack)
{
	if ((nbr > 2147483648 && sign == -1) || (nbr > 2147483647 && sign == 1))
		error_found(stack);
}

int	ps_atoi(char *str, int *stack)
{
	unsigned int	i;
	int				sign;
	unsigned long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	check_digit(str[i], stack);
	while (str[i])
	{
		check_digit(str[i], stack);
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	check_overflow(nbr, sign, stack);
	return (nbr * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

size_t	ft_strlen(char const *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
