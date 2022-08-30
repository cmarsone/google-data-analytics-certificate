/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:55:01 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/24 16:56:44 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 4096

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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	write(1, &fd, 1);
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	buf[ret] = '\0';
	i = 0;
	while (buf[i])
	{
		ft_putstr(buf);
		if (ft_strcmp(argv[2], "-c") == 0)
		{
			lseek(fd, 15, SEEK_END);
		}
		else
		{
			lseek(fd, BUF_SIZE, SEEK_END);
		}
		i++;
	}
	write(1, &ret, 1);
	close(fd);
	if (close(fd) == -1)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	return (0);
}
