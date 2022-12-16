#include "push_swap.h"

int	ft_set_a_2(int *a, int len, char **av)
{
	int		i;
	int		x;
	int		j;
	char	**arr;

	i = 0;
	x = 1;
	while (i < len)
	{
		j = 0;
		arr = ft_split(av[x]);
		if (!arr || !ft_number_of_t_nbrs(av[x]))
			return (free_split(arr), free(a), 0);
		while (arr[j])
		{
			a[i++] = ft_atoi(arr[j++]);
			if (ft_atoi(arr[j - 1]) > 2147483647
				|| ft_atoi(arr[j - 1]) < -2147483648)
				return (free(a), free_split(arr), 0);
		}
		free_split(arr);
		x++;
	}
	return (1);
}

int	*ft_set_a(char **av, int *len)
{
	int	*a;
	int	i;
	int	oldlen;

	oldlen = *len;
	i = 1;
	while (i <= oldlen)
	{
		if (!ft_number_of_t_nbrs(av[i]))
			return (0);
		*len += ft_number_of_t_nbrs(av[i]) - 1;
		i++;
	}
	a = (int *)malloc(sizeof(int) * *len);
	if (!a)
		return (0);
	if (!ft_set_a_2(a, *len, av))
		return (0);
	i = 0;
	return (a);
}

void	ft_do_magic(int	**a, int *a_len, int **b, int *b_len)
{
	int	i;
	int	len_holder;
	int	len_holder2;

	len_holder = *a_len;
	while (*a_len > 3)
	{
		if (is_a_sorted(*a, *a_len))
			break ;
		push_min_to_top(*a, *a_len);
		ft_push_b(a, b, a_len, b_len);
	}
	if (*a_len <= 3)
		ft_do_magic_2(*a, *b, *a_len);
	i = 0;
	len_holder2 = *a_len;
	while (*b_len > 0)
		ft_push_a(a, b, a_len, b_len);
	free(*a);
	free(*b);
}

void	sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*sorted_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	*new_arr;

	new_arr = (int *)malloc(sizeof(int) * len);
	if (!new_arr)
		return (0);
	i = 0;
	while (i < len)
	{
		new_arr[i] = arr[i];
		i++;
	}
	sort_arr(new_arr, len);
	return (new_arr);
}
