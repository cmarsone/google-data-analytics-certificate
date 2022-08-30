/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 09:42:02 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 07:55:52 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	int		i;
	t_list	*last;

	last = ft_create_elem(data);
	i = 0;
	while (begin_list[i])
	{
		while (begin_list[i]->next == 0)
			begin_list[i] = begin_list[i]->next;
		begin_list[i]->next = last;
		i++;
	}
	return ;
}
