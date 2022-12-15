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

void	ft_do_split(t_nbr *t_nbrs, int *sorted_arr, int a_len)
{
	if (a_len <= 100)
		set_x_y(t_nbrs, sorted_arr, a_len, 3);
	else if (a_len <= 200)
		set_x_y(t_nbrs, sorted_arr, a_len, 4);
	else if (a_len <= 300)
		set_x_y(t_nbrs, sorted_arr, a_len, 5);
	else if (a_len <= 400)
		set_x_y(t_nbrs, sorted_arr, a_len, 6);
	else
		set_x_y(t_nbrs, sorted_arr, a_len, 7);
	t_nbrs->i = sorted_arr[(t_nbrs->x / 2) + 1];
	free(t_nbrs->sorted_a);
}

void	do_magic_part2(int **a, int *a_len, int **b, int *b_len)
{
	ft_do_magic_2(*a, *b, *a_len);
	while (*b_len > 0)
	{
		push_max_to_top(*b, *b_len);
		ft_push_a(a, b, a_len, b_len);
	}
	free(*a);
	free(*b);
}

void	ft_do_magic_5(int **a, int *a_len, int **b, int *b_len)
{
	t_nbr	t_nbrs;

	while (*a_len > 3)
	{
		t_nbrs.sorted_a = sorted_arr(*a, *a_len);
		ft_do_split(&t_nbrs, t_nbrs.sorted_a, *a_len);
		if (is_a_sorted(*a, *a_len))
			break ;
		while (t_nbrs.x >= 0)
		{
			if (*a[0] <= t_nbrs.y)
			{
				ft_push_b(a, b, a_len, b_len);
				if (*b[0] < t_nbrs.i && !is_it_closer_from_top(*a, *a_len, t_nbrs.y)
					&& *a[0] > t_nbrs.y)
					ft_rr(*a, *a_len, *b, *b_len);
				else if (*b[0] < t_nbrs.i)
					from_top_to_bottom_b(*b, *b_len);
				t_nbrs.x--;
			}
			else
				from_top_to_bottom(*a, *a_len);
		}
	}
}

int	main_2(int **a, int *a_len, int **b, int *b_len)
{
	if (is_a_sorted(*a, *a_len))
	{
		fre_aandb(*a, *b);
		return (0);
	}
	if (*a_len < 25)
	{
		ft_do_magic(a, a_len, b, b_len);
		return (0);
	}
	ft_do_magic_5(a, a_len, b, b_len);
	do_magic_part2(a, a_len, b, b_len);
	return (1);
}

int	main(int ac, char **av)
{
	int		len;
	int		b_len;
	int		*a;
	int		*b;
	int		i;
	pid_t	pid;

	pid = getpid();
	len = ac - 1;
	b_len = 0;
	a = ft_set_a(av, &len);
	if (!a || ft_check_dup(a, len) || len == 0)
	{
		printf("error!");
		return (0);
	}
	b = (int *)malloc(sizeof(int));
	if (!b)
	{
		free(a);
		printf("error!");
		return (0);
	}
	if (!main_2(&a, &len, &b, &b_len))
		return (0);
	/* printf("a[0] == %i\n", a[0]);
	i = 1;
	while (i < len)
	{
		if (a[i] < a[i - 1])
		{
			printf("i == %i\n", i);
			printf("problem\n");
		}
		printf("a[%i] == %i\n", i, a[i]);
		i++;
	}
	printf("i === %i\n", atoi("481052693876")); */
}
