/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:58:12 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/22 12:29:39 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 5)
		return (1);
	if ((nb % 2) == 0)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i = i + 2 ;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (nb >= 2)
	{
		nb++;
		if (ft_is_prime(nb) == 1)
		{
			return (nb);
		}
	}
	return (2);
}
