#include "push_swap_bonus.h"

void ft_do_split(t_nbr *t_nbrs, int *sorted_arr, int a_len)
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

void do_magic_part2(int **a, int *a_len, int **b, int *b_len)
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

void ft_do_magic_5(int **a, int *a_len, int **b, int *b_len)
{
	t_nbr t_nbrs;

	while (*a_len > 3)
	{
		t_nbrs.sorted_a = sorted_arr(*a, *a_len);
		ft_do_split(&t_nbrs, t_nbrs.sorted_a, *a_len);
		if (is_a_sorted(*a, *a_len))
			break;
		while (t_nbrs.x >= 0)
		{
			if (*a[0] <= t_nbrs.y)
			{
				ft_push_b(a, b, a_len, b_len);
				if (*b[0] < t_nbrs.i && !is_it_closer_from_top(*a, *a_len, t_nbrs.y) && *a[0] > t_nbrs.y)
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

int main_2(int **a, int *a_len, int **b, int *b_len)
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

void test()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	atexit(test);

	t_params nbrs;
	int len;
	int b_len;
	int *a;
	int *b;

	nbrs.a_len = ac - 1;
	nbrs.b_len = 0;
	nbrs.a = ft_set_a(av, &nbrs.a_len);
	if (!nbrs.a || ft_check_dup(nbrs.a, nbrs.a_len))
	{
		write(1, "error\n", 6);
		return (0);
	}
	nbrs.b = (int *)malloc(sizeof(int));
	if (!nbrs.b)
	{
		free(nbrs.a);
		return (0);
	}
	nbrs.a_len = ac - 1;
	nbrs.a = ft_set_a(av, &nbrs.a_len);
	bonus_work(&nbrs.a, &nbrs.a_len, &nbrs.b, &nbrs.b_len);
}
