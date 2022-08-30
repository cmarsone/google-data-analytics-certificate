#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ft_strlen.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include "ft_atoi.c"
 #include "ft_putnbr_base.c"
// #include "ft_atoi_base.c"

int		ft_strlen(char *str);
// void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putnbr_base(int nbr, char *base);
// int		ft_atoi_base(char *str, char *base);

int	main()
{
	char a[] = "   ---+--+1234ab567";
	char b[2] = "01";
	printf("%d", ft_atoi(a));
	ft_putnbr_base(107, b);
	return (0);
}

