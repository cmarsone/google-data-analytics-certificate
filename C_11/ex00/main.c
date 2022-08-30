/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:54:10 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/24 12:28:42 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_foreach.c"

void	ft_putnbr(int nb)
{
	char	w;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		w = (nb % 10) + 48;
		write(1, &w, 1);
	}
}

int	main(void)
{
	int tab[5] = {-2147483648, 2, 3, 4, 5};

	ft_foreach(tab, 5, &ft_putnbr);
	return (0);
}
