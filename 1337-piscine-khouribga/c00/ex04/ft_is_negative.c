#include<unistd.h>
void	ft_is_negative(int n)
{
	char	c;
	char	c1;

	c = 'N';
	c1 = 'P';
	if (n >= 0)
	{
		write(1, &c1, 1);
	}
	else
	{
		write(1, &c, 1);
	}	
}
