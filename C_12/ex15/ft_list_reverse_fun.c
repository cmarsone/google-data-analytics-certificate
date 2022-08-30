/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:08:09 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/25 14:21:43 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	struct s_list	*prev;
	struct s_list	*t;
	struct s_list	*foll;

	while (begin_list)
	{
		foll = begin_list->next;
		begin_list->next = prev;
		prev = t;
		t = foll;
	}
	begin_list = t;
}
