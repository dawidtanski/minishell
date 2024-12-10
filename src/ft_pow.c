#include "../inc/minishell.h"

double ft_pow(double x, double y)
{
	double	result;

	result = 1.0;
	if (y == 0)
		return (1);
	if (y < 0)
	{
		x = 1/x;
		y = -y;
	}
	while (y > 0)
	{
		result *= x;
		y--;
	}
	return (result);
}