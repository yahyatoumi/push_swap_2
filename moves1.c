#include "push_swap.h"

void	from_bottom_to_top(int *a, int len)
{
	int		i;
	int		tmp;
	int		tmp2;

	printf("rra\n");
	i = 1;
	tmp = a[0];
	a[0] = a[len - 1];
	while (i < len)
	{
		tmp2 = a[i];
		a[i] = tmp;
		tmp = tmp2;
		i++;
	}
}

void	from_bottom_to_top_b(int *a, int len)
{
	int		i;
	int		tmp;
	int		tmp2;

	printf("rrb\n");
	i = 1;
	tmp = a[0];
	a[0] = a[len - 1];
	while (i < len)
	{
		tmp2 = a[i];
		a[i] = tmp;
		tmp = tmp2;
		i++;
	}
}

void	swap_first_two(int *a)
{
	int		tmp;

	printf("sa\n");
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	from_top_to_bottom(int *a, int len)
{
	int		i;
	int		tmp;
	int		tmp2;

	printf("ra\n");
	i = 2;
	tmp = a[len - 1];
	a[len - 1] = a[0];
	while (i <= len)
	{
		tmp2 = a[len - i];
		a[len - i] = tmp;
		tmp = tmp2;
		i++;
	}
}

void	from_top_to_bottom_b(int *a, int len)
{
	int	i;
	int	tmp;
	int	tmp2;

	printf("rb\n");
	i = 2;
	tmp = a[len - 1];
	a[len - 1] = a[0];
	while (i <= len)
	{
		tmp2 = a[len - i];
		a[len - i] = tmp;
		tmp = tmp2;
		i++;
	}
}
