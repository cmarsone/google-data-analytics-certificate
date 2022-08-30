/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:54:10 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 08:16:34 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*element;

	while (begin_list)
	{
		free_fct(begin_list->data);
		element = begin_list;
		begin_list = begin_list->next;
		free(element);
	}
	free(begin_list);
	return ;
}
