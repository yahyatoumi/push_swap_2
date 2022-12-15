#include "push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	fre_aandb(int *a, int *b)
{
	free(a);
	free(b);
}

int	max_index(int *a, int len)
{
	int	i;
	int	indx;

	i = 1;
	indx = 0;
	while (i < len)
	{
		if (a[indx] < a[i])
			indx = i;
		i++;
	}
	return (indx);
}

int	min_index(int *a, int len)
{
	int	i;
	int	indx;

	i = 1;
	indx = 0;
	while (i < len)
	{
		if (a[indx] > a[i])
			indx = i;
		i++;
	}
	return (indx);
}

void	push_min_to_top(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	j = min_index(a, len);
	if (j <= (len / 2))
	{
		while (i < j)
		{
			from_top_to_bottom(a, len);
			i++;
		}
	}
	else
	{
		while (i + j < len)
		{
			from_bottom_to_top(a, len);
			i++;
		}
	}
}
