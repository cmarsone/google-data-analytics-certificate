/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:19:20 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/25 13:53:51 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	int	i;

	i = 0;
	while (begin_list[i])
	{
		if ((*cmp)(begin_list[i]->data, data_ref) == 0)
		{
			(*free_fct)(begin_list[i]->data);
		}
		begin_list[i] = begin_list[i]->next;
		i++;
	}
	return ;
}
