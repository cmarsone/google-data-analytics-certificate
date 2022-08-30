/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:52:40 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/20 07:54:21 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	else if (nb > 0)
	{
		return (res * ft_recursive_factorial(nb - 1));
	}
	return (0);
}
