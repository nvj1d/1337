#include<unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int a, int b, int c, int d)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(' ');
	ft_putchar(c + 48);
	ft_putchar(d + 48);
	if (a != 9 || b != 8 || c != 9 || d != 9)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print(a / 10, a % 10, b / 10, b % 10);
			b++;
		}
		a++;
	}
}
