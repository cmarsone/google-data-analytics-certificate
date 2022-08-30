/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:54:43 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/25 14:07:26 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list **a, t_list **b)
{
	struct s_list	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int	i;
	int	j;

	i = 1;
	while (begin_list[i])
	{
		j = i + 1;
		while (begin_list[j])
		{
			if ((*cmp)(begin_list[i - 1]->data, begin_list[j]->data) > 0)
				ft_swap(&begin_list[i - 1], &begin_list[i]);
			j++;
		}
		i++;
	}
	return ;
}
