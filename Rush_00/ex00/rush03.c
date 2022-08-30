/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelafos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:23:17 by vdelafos          #+#    #+#             */
/*   Updated: 2022/08/14 17:44:25 by vdelafos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rush(int x, int y, int i, int j)
{
	if (((i == 0) && (j == 0))
		|| ((i == 0) && (j == (y - 1))))
		ft_putchar('A');
	else if (((i == (x - 1)) && (j == 0))
		|| ((i == (x - 1)) && (j == (y - 1))))
		ft_putchar('C');
	else if ((i == 0) || (i == (x - 1)))
		ft_putchar('B');
	else if ((j == 0) || (j == (y - 1)))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if ((x > 0) && (y > 0))
	{
		j = 0;
		while (j < y)
		{
			i = 0;
			while (i < x)
			{
				print_rush(x, y, i, j);
				i++;
			}
			j++;
			ft_putchar('\n');
		}
	}
}
