/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:13:14 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/25 13:18:58 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	struct s_list	*t;

	while (begin_list)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
		{
			t = begin_list;
			return (t);
		}
	}
	return (0);
}
