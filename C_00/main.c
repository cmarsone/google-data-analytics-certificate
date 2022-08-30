/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:47:28 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/10 17:21:21 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

// #include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
// #include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
// #include "ex08/ft_print_combn.c"

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);
void	ft_print_comb2(void);
void	ft_putnbr(int nb);
/*void	ft_print_combn(int n);
void    print_numn(int n); */


int	main(void)
{
	// Exercice 00
	char	c;
	printf("Enter a parameter: \n");
	scanf("%c", &c);
	ft_putchar(c);
	printf("\n");

	// Exercice 01
	ft_print_alphabet();
	printf("\n");

	// Exercice 02
	ft_print_reverse_alphabet();
	printf("\n");

	// Exercice 03
	ft_print_numbers();
	printf("\n");

	// Exercice 04
	int	a;
	
	printf("Enter a parameter: \n");
	scanf("%d", &a);
	ft_is_negative(a);
	printf("\n");

	// Exercice 05
	// ft_print_comb();
	printf("\n");

	// Exercice 06
	ft_print_comb2();
	printf("\n");

	// Exercice 07

	int	nb;	
	printf("Enter a parameter: \n");
	scanf("%d", &nb);
	ft_putnbr(nb);
	printf("\n");

	// Exercice 08
	
	//int	n;
	
    //printf("Enter a parameter: \n");
	//scanf("%d", &n);
	//ft_print_combn(n);

	return(0);
}
