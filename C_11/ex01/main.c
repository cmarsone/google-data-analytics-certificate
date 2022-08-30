/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:05:47 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/24 12:03:13 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_map.c"


int	ft_putnbr(int nb)
{
	return nb;
}

int	main(void)
{
	int t[] = {1, 2, 3, 4, 5};

	printf("%d", ft_map(t, 5, &ft_putnbr));
	return (0);
}
