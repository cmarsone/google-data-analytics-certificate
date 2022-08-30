/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:27:57 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/19 09:35:59 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_except(int tbase, long nbr, char *base)
{
	long	tbase2;

	tbase2 = tbase;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > tbase2)
		ft_except(tbase, nbr / tbase2, base);
	else if (tbase == 2 && nbr > 1)
		write(1, &base[1], 1);
	nbr = nbr % tbase;
	write(1, &base[nbr], 1);
}

int	ft_calc_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		tbase;

	tbase = ft_calc_base(base);
	if (tbase < 2)
		return ;
	if (nbr == -2147483648)
		ft_except(tbase, -2147483648, base);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr > tbase)
			ft_putnbr_base(nbr / tbase, base);
		else if (tbase == 2 && nbr > 1)
			write(1, &base[1], 1);
		nbr = nbr % tbase;
		write(1, &base[nbr], 1);
	}
}
