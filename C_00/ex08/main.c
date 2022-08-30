/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 07:52:30 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/29 10:33:31 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

void	display(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(arr[i]);
		if (i % 2 == 1 && arr[0] != 10 - n)
		{	
			write(1, ",", 1);
			write(1, " ", 1);
		}
		i++;
	}
}

void	runner(int arr[], int n, int i)
{
	if (arr[0] == 10 - n)
	{
		display(arr, n);
		return ;
	}
	while (i < n)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
	i--;
	while (arr[i] <= 10 - i - 1)
	{
		display(arr, n);
		arr[i]++;
	}
	display(arr, n);
	while (arr[i] >= 10 - i - 1)
		i--;
	arr[i]++;
	runner(arr, n, i++);
}

void	ft_print_combn(int n)
{
	int	arr[9];

	arr[0] = 0;
	if (n > 0 && n < 10)
		runner(arr, n, 0);
}

int	main(void)
{
	ft_print_combn(2);
	return (0);
}
