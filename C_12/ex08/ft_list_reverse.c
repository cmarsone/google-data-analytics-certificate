/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:09:24 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 08:20:25 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*t;
	t_list	*foll;
	t_list	*prev;

	t = *begin_list;
	while (*begin_list)
	{
		foll = t->next;
		t->next = prev;
		prev = t;
		t = foll;
	}
	*begin_list = t;
	return ;
}
