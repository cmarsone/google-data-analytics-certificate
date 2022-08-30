/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:31:30 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/23 14:31:32 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft.h"
#include "ft_abs.h"
#include "ft_stock_str.h"
#include "ft_strs_to_tab.c"
#include "ft_show_tab.c"

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ABS(-1 * 3));
	return (0);
}
