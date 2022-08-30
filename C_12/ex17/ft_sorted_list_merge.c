/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:48 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 08:22:19 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	int	i;

	i = 0;
	while (begin_list2 && begin_list1[i + 1])
	{
		if ((*cmp)(begin_list1[i]->data, begin_list2->data) > 0
			&& (*cmp)(begin_list2->data, begin_list1[i + 1]->data))
		{
			begin_list1[i]->next = begin_list2;
			begin_list1[i] = begin_list1[i]->next->next;
			begin_list2 = begin_list2->next;
		}
		else
		{
			begin_list1[i] = begin_list1[i]->next;
		}
		i++;
	}
	return ;
}
