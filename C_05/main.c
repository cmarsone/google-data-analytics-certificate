/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:39:15 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/22 08:50:54 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h> 
// #include "ex00/ft_iterative_factorial.c"
//  #include "ex01/ft_recursive_factorial.c"
// #include "ex02/ft_iterative_power.c"
//#include "ex03/ft_recursive_power.c"
//#include "ex04/ft_fibonacci.c"
//#include "ex05/ft_sqrt.c"
//#include "ex06/ft_is_prime.c" 
#include "ex07/ft_find_next_prime.c"
// #include "ex08/ft_ten_queens_puzzle.c"

int    main()
{
    int a = 2;
    int b = 3;
//    printf("%d\n", ft_recursive_power(a, b));

//    printf("%d\n", ft_fibonacci(7));
//    printf("%d\n", ft_sqrt(16));
    printf("%d\n", ft_is_prime(7919));
    printf("%d\n", ft_find_next_prime(5));
    return (0);
}
