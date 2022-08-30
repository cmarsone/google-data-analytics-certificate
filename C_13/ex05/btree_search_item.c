/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:34:35 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/26 11:45:10 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (!root)
		return (0);
	btree_search_item(root->left, data_ref, cmpf);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	btree_search_item(root->right, data_ref, cmpf);
	return (0);
}
