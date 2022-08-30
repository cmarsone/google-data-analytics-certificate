/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:15:45 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/28 17:34:58 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 690

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
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

int	main(int argc, char **argv)
{
	int		i = 0;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char 	**res;
	char 	**res2;


	if (argc < 4)
	{
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] > '9' || argv[1][i] < '0')
		{
			write(1, "Error", 5);
			return (0);
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		if (argv[2][i] > 'a' || argv[2][i] < 'z')
		{
			write(1, "Error", 5);
			return (0);
		}
		i++;
	} 	
	res = (char**)malloc(BUF_SIZE + 1 + ft_strlen(argv[1]) + ft_strlen(argv[2]));
	res2 = (char**)malloc(BUF_SIZE + 1 + ft_strlen(argv[1]) + ft_strlen(argv[2]));	
	
	if (!res || !res2)
		return (0);	
		if (argc > 3)
	{
		write(1, "Error", 5);
		return (0);
	}
	fd = open("numbers.dict", O_RDWR);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
		return(0);
	buf[ret] = '\0';
	
	i = 0;
	int j;
   j	= 0;
	int k;
   k	= 0;
 
	while (buf[i])
	{
		k = 0;
		while (buf[i]>= '0' && buf[i] <= '9')
		{	
			res[j][k] = buf[i];
			k++;
			i++;
		}
		i--;
		while (buf[i] != '\n')
			i++;
		j++;
		i++;
	}

	i = 0;
	j = 0;
	while (buf[i])
	{
		k = 0;
		while (!(buf[i]>= 'a' && buf[i] <= 'z'))
			i++;
		while (buf[i]>= 'a' && buf[i] <= 'z')
		{	
			res2[j][k] = buf[i];
			k++;
			i++;
		}
		j++;
		i++;
	}
	
		i = 0;
		while (i < 43)
		{
			if (ft_strcmp(argv[1], res[i]) == 0)
				ft_strcpy(res2[i], argv[2]);
			i++;
		}
		write(fd, "\n", 1);	
		write(fd, argv[1], ft_strlen(argv[1]));
		write(fd, ": ", 2);
		write(fd, argv[2], ft_strlen(argv[2]));


	close(fd);
	if (close(fd) == -1)
		return (0);

	}
	return (0);
}
