/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:21:17 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/26 11:34:08 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	int	i;

	if (!root)
		return ;
	i = 0;
	while (root[i])
	{
		btree_insert_data(&root[i]->left, item, cmpf);
		if ((*cmpf)(root[i]->left, root[i]->item) < 0
			&& (*cmpf)(root[i]->item, root[i]->right) < 0)
		{
			root[i]->item = item;
		}
		btree_insert_data(&root[i]->right, item, cmpf);
		i++;
	}	
	return ;
}
