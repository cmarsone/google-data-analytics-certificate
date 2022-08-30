/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:22:53 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 08:22:03 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	struct s_list	*elem;

	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	int				i;
	struct s_list	*t;

	t = ft_create_elem(data);
	i = 0;
	while (begin_list[i])
	{
		if (begin_list[i + 1])
		{
			if ((*cmp)(begin_list[i]->data, t->data) > 0
				&& (*cmp)(begin_list[i + 1]->data, t->data < 0))
			{
				begin_list[i]->next = t;
				begin_list[i] = begin_list[i]->next->next;
			}
			else
			{
				begin_list[i] = begin_list[i]->next;
			}
		}
		i++;
	}
	return ;
}
