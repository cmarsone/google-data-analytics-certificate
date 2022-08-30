/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 09:29:42 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/16 10:58:26 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	a;

	a = 0;
	ft_ft(&a);
	printf("%d\n", a);
	int	*a1;

	/* *a1 = &a;
	int	**a2;

	**a2 = &a1;
	int	***a3;

	***a3 = &a2;
	int	****a4;

	****a4 = &a3;
	int	*****a5;

	*****a5 = &a4;
	int	******a6;

	******a6 = &a5;
	int	*******a7;

	*******a7 = &a6;
	int	********a8;

	********a8 = &a7;
	int	*********a9;

	*********a9 = &a8;
	ft_ultimate_ft(a9);
	printf("%d\n", a); */
	int	b; 

	b = 1;
	ft_swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
	int	div;

	int	mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d [%d]\n", a, b, div, mod);
	ft_ultimate_div_mod(&a, &b);
	printf("a / b = %d [%d]\n", a, b);
	char	mot[] = "JESUS";
	ft_putstr(mot);
	printf("length: %d\n", ft_strlen(mot));
	int	size;

	size = 4;
	int	tab[4] = {0, 1, 2, 3};
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
	ft_rev_int_tab(tab, size);
	i = 0 ;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(tab, size);
	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	c;

	c = a / b;
	*div = c;
	c = a % b;
	*mod = c;
}

void	ft_ultimate_div_mod(int *a, int*b)
{
	int	div;
	int	rest;

	div = *a / *b;
	rest = *a % *b;
	*a = div;
	*b = rest;
}

void	ft_putstr(char *str)
{
	int	i;
	char	a;

	i = 0;
	while (str[i])
	{
		a = str[i];
		write(1, &a, 1);
		i++;
	}
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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < size / 2)
	{
		j = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = j;
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;
	int res[size];

	i = 0;
	k = tab[0];
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (k < tab[j])
			{
				res[i] = tab[j];
			}
			j++;
		}
		i++;
		k = tab[i];
	}
	tab = res;
}
