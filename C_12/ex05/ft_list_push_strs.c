/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:41:15 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 08:03:05 by cmarsone         ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*elem;

	elem = ft_create_elem(strs);
	i = 0;
	while (i < size - 1)
	{
		elem->data = strs[i + 1];
		elem = elem->next;
		i++;
	}
	elem->data = strs[0];
	elem->next = NULL;
	return (elem);
}
