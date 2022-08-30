/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:01:52 by cmarsone          #+#    #+#             */
/*   Updated: 2022/08/28 17:08:35 by cmarsone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_putstr(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

unsigned int ft_atoi(char *str)
{
    int i;
    unsigned int value;
    unsigned int sign;

    i = 0;
    value = 0;
    sign = 1;
    
    while (str[i] == ' ' || (str[i] > 7 && str[i] < 14))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    return (value * sign);
}

char    *ft_strcat(char *dest, char *src)
{
    int    i;
    int    j;

    i = 0;
    while (dest[i])
    {
        i++;
    }
    j = 0;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
char *remove_space_and_return(char *str)
{
    int size;
    
    size = ft_strlen(str);
    str[size - 1] = '\0';
    return (str);
}
void convert(unsigned int nbr)
{
    char answer[2048];
    unsigned long long int i;
    unsigned long long int limit = 1000000000000;
    unsigned long long int current = 0;
    int j;
    
    if (nbr == 0)
    {
        ft_putstr("zero");
        return ;
    }
    char from_thousand_to_trillion[5][12] = { "", "trillion", "billion", "million", "thousand" };
    char from_one_to_nineteen[20][20] = {
        "",        "one",       "two",      "three",
        "four",    "five",      "six",      "seven",
        "eight",   "nine",      "ten",      "eleven",
        "twelve",  "thirteen",  "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };
    char from_twenty_to_ninety[9][20]
        = { "",      "twenty",  "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety" };
     
    if (nbr < 20)
    {
        ft_putstr(from_one_to_nineteen[nbr]);
        return ;
    }
    i = nbr;
    j = 0;
    while (i > 0) {
         
        current = i / limit;
        while (current == 0) {
            i %= limit;
            limit /= 1000;
            current = i / limit;
            ++j;
        }
        if (current > 99)
        {
            ft_strcat(answer, (from_one_to_nineteen[current / 100]));
            ft_strcat(answer, (" hundred "));
        }
        current = current % 100;
        if (current > 0 && current < 20)
        {
           
            ft_strcat(answer, (from_one_to_nineteen[current]));
            ft_strcat(answer, (" "));
        }
        else if (current % 10 == 0 && current != 0)
        {
            ft_strcat(answer,from_twenty_to_ninety[current / 10 - 1]);
            ft_strcat(answer, (" "));
        }
        else if (current > 20 && current < 100)
        {
             ft_strcat(answer,from_twenty_to_ninety[current / 10 - 1]);
             ft_strcat(answer, (" "));
             ft_strcat(answer,from_one_to_nineteen[current % 10]);
             ft_strcat(answer, (" "));
        }
        if (j < 4)
        {
             ft_strcat(answer, from_thousand_to_trillion[++j]);
             ft_strcat(answer, (" "));
        }
        i = i % limit;
        limit = limit / 1000;
    }
    ft_putstr(remove_space_and_return(answer));
}

int    main(int argc, char **argv)
{
    unsigned int nbr;
    
    if (argc > 1 && argc < 3)
    {
        int size = ft_strlen(argv[1]);
        if (size == 0)
        {
            ft_putstr("Error\n");
            return (-1);
        }
        nbr = ft_atoi(argv[1]);
        if (nbr == 4294967295 || nbr < 0)
        {
            ft_putstr("Error\n");
            return (-1);
        }
        convert(nbr);
        ft_putchar('\n');
    }
    return (0);
}
