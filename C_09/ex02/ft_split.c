/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 08:16:56 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/29 17:40:53 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdlib.h>

int	ft_is_sp(char c, char *sp)
{
	int	i;

	i = 0;
	while (sp[i])
	{
		if (sp[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_countw(char *str, char *sp)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_sp(str[i], sp) && str[i])
			i++;
		if (!ft_is_sp(str[i], sp) && str[i])
		{
			k++;
			while (!ft_is_sp(str[i], sp) && str[i])
				i++;
		}
	}
	return (k);
}

int	ft_count(char *str, char *sp)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sp(str[i], sp))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		a;
	int		k;
	int		j;

	k = 0;
	i = 0;
	split = malloc(sizeof(char *) * (ft_countw(str, charset) + 1));
	while (*str)
	{
		j = 0;
		a = ft_count(str, charset);
		if (a)
		{
			split[k] = malloc(a + 1);
			while (!ft_is_sp(*str, charset) && str[i])
				split[k][j++] = *str++;
			split[k][j] = '\0';
			k++;
		}
		str++;
	}
	split[k] = 0;
	return (split);
}
