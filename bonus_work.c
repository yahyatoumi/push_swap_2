#include "get_next_line.h"
#include "push_swap_bonus.h"

int check_if_sorted(int *a, int a_len)
{
	int i;
	int j;

	i = 0;
	while (i < a_len)
	{
		j = i + 1;
		while (j < a_len)
		{
			if (a[i] > a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_rrr(int **a, int *a_len, int **b, int *b_len)
{
	from_bottom_to_top_bonus(*a, *a_len);
	from_bottom_to_top_b_bonus(*b, *b_len);
}

void ft_ss(int **a, int **b)
{
	swap_first_two_bonus(*b);
	swap_first_two_bonus(*a);
}

void bonus_work(int **a, int *len, int **b, int *b_len)
{
	int i;
	char *move;

	i = 0;
	move = (get_next_line(0));
	while (move)
	{
		if (!strcmp(move, "ra\n"))
			from_top_to_bottom_bonus(*a, *len);
		else if (!strcmp(move, "rb\n") && *b_len > 2)
			from_top_to_bottom_bonus(*b, *b_len);
		else if (!strcmp(move, "rra\n"))
			from_bottom_to_top_bonus(*a, *len);
		else if (!strcmp(move, "rrb\n") && *b_len > 0)
			from_bottom_to_top_bonus(*b, *b_len);
		else if (!strcmp(move, "sa\n") && *len > 1)
			swap_first_two_bonus(*a);
		else if (!strcmp(move, "sb\n") && *b_len > 1)
			swap_first_two_bonus(*b);
		else if (!strcmp(move, "pb\n") && *len > 0)
			ft_push_b_bonus(a, b, len, b_len);
		else if (!strcmp(move, "pa\n") && *b_len > 0)
			ft_push_a_bonus(a, b, len, b_len);
		else if (!strcmp(move, "rr\n") && *b_len > 1 && *len > 1)
			ft_rr_bonus(*a, *len, *b, *b_len);
		else if (!strcmp(move, "rrr\n") && *b_len > 1 && *len > 1)
			ft_rrr(a, len, b, b_len);
		else if (!strcmp(move, "ss\n") && *b_len > 1 && *len > 1)
			ft_ss(a, b);
		else
		{
			write(1, "error\n", 6);
			return;
		}
		// i = 0;
		// while (i < *len)
		// {
		// 	printf("a[%i] == %i\n", i, (*a)[i]);
		// 	i++;
		// }
		move = get_next_line(0);
	}
	if (check_if_sorted(*a, *len) && *b_len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
