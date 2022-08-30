/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:52:08 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/30 15:11:14 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	ft_display_file(int fd)
{
	char	buf;

	while (read(fd, &buf, 1))
		write(1, &buf, 1);
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

int	main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	fd = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_DIRECTORY);
		if (fd != -1)
		{
			ft_errors(argv[0], argv[i], 1, -1);
			return (0);
		}
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_errors(argv[0], argv[i], 0, fd);
			return (0);
		}
		ft_display_file(fd);
		i++;
	}
	close(fd);
	return (0);
}
