#include "push_swap.h"

int	devide_or_multiply(int nb)
{
	if (nb < 0)
		return (nb / 2);
	return (nb * 2);
}

void	set_x_y(t_nbr *t_nbrs, int *sorted_arr, int a_len, int devider)
{
	t_nbrs->y = sorted_arr[a_len / devider];
	t_nbrs->x = a_len / devider;
}

int	biggest_n_index(int *arr, int len)
{
	int	i;
	int	indx;

	indx = 0;
	i = 1;
	while (i < len)
	{
		if (arr[i] > arr[indx])
			indx = i;
		i++;
	}
	return (indx);
}

int	is_it_closer_from_top(int *a, int len, int nb)
{
	int	i;
	int	j;

	i = 0;
	j = len - 1;
	while (i < len)
	{
		if (a[i] <= nb)
			break ;
		i++;
	}
	while (j > 0)
	{
		if (a[j] <= nb)
			break ;
		j--;
	}
	if (i <= (len - j))
		return (0);
	else
		return (1);
}

void	push_max_to_top(int *b, int len)
{
	int	i;
	int	j;

	i = 0;
	j = max_index(b, len);
	if (j <= (len / 2))
	{
		while (i < j)
		{
			from_top_to_bottom_b(b, len);
			i++;
		}
	}
	else
	{
		while (i + j < len)
		{
			from_bottom_to_top_b(b, len);
			i++;
		}
	}
}
