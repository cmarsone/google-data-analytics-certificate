/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:29:31 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/21 07:57:18 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] && i < size)
		++i;
	j = 0;
	while (src[j] && size && (j + i < size - 1))
	{
		dest[i + j] = src[j];
		++j;
	}
	if (size && i < size)
		dest[i + j] = '\0';
	j = 0;
	while (src[j])
		++j;
	return (i + j);
}
