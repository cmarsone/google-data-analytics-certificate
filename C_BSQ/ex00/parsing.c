/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:51:26 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/31 10:20:54 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*ft_strncat_malloc(char *old, char *src, int n)
{
	int			i;
	int			oldlen;
	char		*ret;

	ret = malloc((ft_strlen(old) + n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (old[++i])
		ret[i] = old[i];
	ret[i] = 0;
	oldlen = ft_strlen(old);
	i = 0;
	while (src[i] && i < n)
	{
		ret[oldlen + i] = src[i];
		i++;
	}
	ret[oldlen + i] = 0;
	free(old);
	return (ret);
}

int	ft_get_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int	ft_first_line(char *str_map, t_map *map)
{
	int	eofl;
	int	i;

	eofl = 0;
	i = 0;
	while (str_map[eofl] && str_map[eofl] != '\n')
		eofl++;
	if (eofl < 4)
		return (0);
	map->plein = str_map[eofl - 1];
	map->obs = str_map[eofl - 2];
	map->vide = str_map[eofl - 3];
	map->lines = ft_antoi(str_map, (eofl - 3));
	if (map->lines <= 0 || map->obs == map->vide || map->obs == map->plein
		|| map->plein == map->vide)
		return (0);
	map->length = ft_get_line_length(str_map + eofl + 1);
	return (1);
}

int	ft_get_map_size(int *fd, char *file)
{
	int		has_r;
	int		total_l;
	char	c;

	c = 1;
	total_l = 0;
	has_r = 1;
	while (has_r)
	{
		has_r = read(*fd, &c, 1);
		total_l += has_r;
	}
	close(*fd);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (-1);
	return (total_l);
}

t_map	*ft_map(char *file)
{
	t_map	*map;
	char	*str_map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	else
	{
		map = malloc(sizeof(t_map));
		if (!map)
			return (NULL);
		str_map = process_file(fd, ft_get_map_size(&fd, file));
		if (ft_first_line(str_map, map)
			&& ft_map_ok(str_map, map) == map->lines)
			map->map = str_to_matrix(str_map, map->obs, map->vide);
		else
		{
			free(str_map);
			return (0);
		}
	}
	close(fd);
	return (map);
}
