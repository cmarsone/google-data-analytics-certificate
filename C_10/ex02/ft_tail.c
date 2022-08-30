/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:25:02 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/29 17:17:26 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

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

int		size_files(int i, char **argv)
{
	int		fd2;
	char	buffer;
	int		size;

	size = 0;
	fd2 = open(argv[i], O_RDONLY);
	while (read(fd2, &buffer, 1))
		size++;
	close(fd2);
	return (size);
}

void	ft_display_file(int fd, int size, int i, char **argv)
{
	char	buf;
	int		j;

	j = 0;
	while (read(fd, &buf, 1) && j < size_files(i, argv) - size - 1)
		j++;
	while (read(fd, &buf, 1) && j < size_files(i, argv))
	{
		write(1, &buf, 1);
		j++;
	}
	return ;
}

void	ft_errors(char *program_name, char *file_name, int is_dir, int fd)
{
	if (fd == -1)
	{
		ft_putstr(basename(program_name));
		ft_putstr(": ");
		ft_putstr(file_name);
		ft_putstr(": ");
		if (is_dir)
			ft_putstr("Is a directory");
		else
			ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
	return ;
}

int	isNumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void	cat(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 3;
	fd = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_DIRECTORY);
		if (fd != -1)
		{
			ft_errors(argv[0], argv[i], 1, -1);
			return ;
		}
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_errors(argv[0], argv[i], 0, fd);
			return ;
		}
		ft_display_file(fd, ft_atoi(argv[2]), i,  argv);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		write(1, "tail: option requires an argument -- c\n", 39);
		write(1, "usage: tail [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 64);
		return (0);
	}
	if (isNumber(argv[2]) == 0)
	{
		write(1, "tail: illegal offset -- ", 22);
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		return (0);
	}
	if (argv[2] && !argv[3])
		while (1);
	cat(argc, argv);
	return (0);
}
