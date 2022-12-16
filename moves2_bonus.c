#include "push_swap_bonus.h"

void	ft_push_b_bonus(int **a, int **b, int *a_len, int *b_len)
{
	int		b_new_len;
	int		a_new_len;

	b_new_len = *b_len;
	a_new_len = *a_len;
	*b = ft_add_to_stack(*b, &b_new_len, *a[0]);
	*a = ft_stack_without_first(*a, &a_new_len);
	*b_len = b_new_len;
	*a_len = a_new_len;
}

void	ft_push_a_bonus(int **a, int **b, int *a_len, int *b_len)
{
	int		b_new_len;
	int		a_new_len;

	b_new_len = *b_len;
	a_new_len = *a_len;
	*a = ft_add_to_stack(*a, &a_new_len, *b[0]);
	*b = ft_stack_without_first(*b, &b_new_len);
	*b_len = b_new_len;
	*a_len = a_new_len;
}

void	ft_rr_bonus(int *a, int a_len, int *b, int b_len)
{
	int		i;
	int		tmp;
	int		tmp2;

	i = 2;
	tmp = a[a_len - 1];
	a[a_len - 1] = a[0];
	while (i <= a_len)
	{
		tmp2 = a[a_len - i];
		a[a_len - i++] = tmp;
		tmp = tmp2;
	}
	i = 2;
	tmp = b[b_len - 1];
	b[b_len - 1] = b[0];
	while (i <= b_len)
	{
		tmp2 = b[b_len - i];
		b[b_len - i++] = tmp;
		tmp = tmp2;
	}
}
