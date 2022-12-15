#include "push_swap.h"

int	*ft_add_to_stack(int *arr, int *len, int to_add)
{
	int		*new_arr;
	int		i;

	new_arr = (int *)malloc(sizeof(int) * (*len + 1));
	if (!new_arr)
		return (0);
	i = 1;
	new_arr[0] = to_add;
	while (i <= *len)
	{
		new_arr[i] = arr[i - 1];
		i++;
	}
	free(arr);
	*len += 1;
	return (new_arr);
}

int	*ft_stack_without_first(int *arr, int *len)
{
	int		*new_arr;
	int		i;

	new_arr = (int *)malloc(sizeof(int) * (*len - 1));
	if (!new_arr)
		return (0);
	i = 0;
	while (i < *len - 1)
	{
		new_arr[i] = arr[i + 1];
		i++;
	}
	*len -= 1;
	free(arr);
	return (new_arr);
}

void	ft_push_b(int **a, int **b, int *a_len, int *b_len)
{
	int		b_new_len;
	int		a_new_len;

	printf("pb\n");
	b_new_len = *b_len;
	a_new_len = *a_len;
	*b = ft_add_to_stack(*b, &b_new_len, *a[0]);
	*a = ft_stack_without_first(*a, &a_new_len);
	*b_len = b_new_len;
	*a_len = a_new_len;
}

void	ft_push_a(int **a, int **b, int *a_len, int *b_len)
{
	int		b_new_len;
	int		a_new_len;

	printf("pa\n");
	b_new_len = *b_len;
	a_new_len = *a_len;
	*a = ft_add_to_stack(*a, &a_new_len, *b[0]);
	*b = ft_stack_without_first(*b, &b_new_len);
	*b_len = b_new_len;
	*a_len = a_new_len;
}

void	ft_rr(int *a, int a_len, int *b, int b_len)
{
	int		i;
	int		tmp;
	int		tmp2;

	printf("rr\n");
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
