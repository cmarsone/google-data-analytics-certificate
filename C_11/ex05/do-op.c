/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:51:59 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/29 18:18:21 by cmarsone         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	n;

	i = 0;
	nbr = 0;
	n = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (n % 2 == 1)
		return (-nbr);
	return (nbr);
}

void	ft_op(int a, char *b, int c)
{
	if (ft_strcmp(b, "+") == 0)
		ft_putnbr(a + c);
	if (ft_strcmp(b, "-") == 0)
		ft_putnbr(a - c);
	if (ft_strcmp(b, "*") == 0)
		ft_putnbr(a * c);
	if (ft_strcmp(b, "/") == 0)
		ft_putnbr(a / c);
	if (ft_strcmp(b, "%") == 0)
		ft_putnbr(a % c);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strcmp(argv[2], "+") && ft_strcmp(argv[2], "-")
		&& ft_strcmp(argv[2], "*") && ft_strcmp(argv[2], "/")
		&& ft_strcmp(argv[2], "%"))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (ft_strcmp(argv[2], "/") == 0 && ft_strcmp(argv[3], "0") == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (ft_strcmp(argv[2], "%") == 0 && ft_strcmp(argv[3], "0") == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_op(ft_atoi(argv[1]), argv[2], ft_atoi(argv[3]));
	return (0);
}
