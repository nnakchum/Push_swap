/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:18:46 by nnakchum          #+#    #+#             */
/*   Updated: 2024/10/11 18:30:57 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_memo(t_list *list)
{
	int	i;
	int	len;

	if (list == NULL)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->memo[i])
		{
			if (list->memo[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}
	return (len);
}

t_list	*find_last_node(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	get_str(t_list *list, char *str)
{
	int	len;
	int	i;

	if (list == NULL)
		return ;
	len = 0;
	while (list)
	{
		i = 0;
		while (list->memo[i])
		{
			if (list->memo[i] == '\n')
			{
				str[len++] = '\n';
				str[len] = '\0';
				return ;
			}
			str[len++] = list->memo[i++];
		}
		list = list->next;
	}
	str[len] = '\0';
}

int	get_new_line(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->memo[i] && i < BUFFER_SIZE)
		{
			if (list->memo[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}

void	free_node(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->memo);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (buf && clean_node->memo[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
