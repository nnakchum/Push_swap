/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:36:23 by nnakchum          #+#    #+#             */
/*   Updated: 2024/11/16 21:17:46 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_check(va_list *args, char c);
int		ft_putnbr(long nb);
int		ft_putnbr_u(unsigned int nb);
int		ft_putnbr_x(unsigned long nb);
int		ft_putnbr_xb(unsigned int nb);
int		ft_putnbr_p(unsigned long nb);

#endif
