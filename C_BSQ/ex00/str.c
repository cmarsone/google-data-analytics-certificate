/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:52:57 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/31 08:53:19 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_antoi(char *str, int n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && i < n)
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	**str_to_matrix(char *str, char obst, char empty)
{
	int		trimm_offset;
	int		**int_matrix;
	char	chrs[2];

	chrs[0] = obst;
	chrs[1] = empty;
	trimm_offset = 0;
	while (str[trimm_offset] && str[trimm_offset] != '\n')
		trimm_offset++;
	int_matrix = ft_split_number(str + trimm_offset, "\n", chrs);
	if (!int_matrix)
		return (NULL);
	return (int_matrix);
}
