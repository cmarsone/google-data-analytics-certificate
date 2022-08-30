/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:47:09 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/25 13:52:58 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	int	i;

	i = 0;
	while (begin_list1[i])
	{
		if (!begin_list1[i + 1])
		{
			begin_list1[i]->next = begin_list2;
			return ;
		}
		i++;
	}
	return ;
}
