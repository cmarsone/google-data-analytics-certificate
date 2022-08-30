/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 07:57:50 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/28 13:02:33 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		dest[i] = src[i];
		i++;
	}
    dest[i] = 0;
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}



int 	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

int		ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 0 && str[i] <= 9))
		{
			return (0);
		}
	i++;
	}
	return (1);

}

int		ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

int ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= ' ' && str[i] <= '~'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
	i++;
	}
	return (str);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
	i++;
	}
	return (str);
}

char    *ft_strcapitalize(char *str)
{
    int    i;

	if (ft_str_is_lowercase(&str[0]) && ft_str_is_alpha(&str[1]))
		str[0] -= 32;
	i = 1;
    while (str[i + 1])
    {
		while (ft_str_is_alpha(&str[i]))
		{
			if (ft_str_is_uppercase(&str[i]))
				ft_str_is_lowercase(&str[i]);
			i++;
		}
		while (!ft_str_is_alpha(&str[i]))
			i++;
        if (ft_str_is_lowercase(&str[i])
        	&& ft_str_is_alpha(&str[i + 1])
        	&& !ft_str_is_numeric(&str[i - 1]))
            str[i] = str[i] - 32;
        i++;
	}
    return (str);
}

int	main(void)
{
	char	src[61] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	res[62];
	strcpy(res, ft_strcapitalize(src));
	printf("%s\n", res);
	return (0);
}

