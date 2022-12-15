#include "push_swap.h"

int	ft_atoi_checker(char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-' && str[0] != '+' && (str[0] < '0' || str[0] > '9'))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					i;
	int					np;

	np = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((np * num));
}

int	ft_check_dup(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] == a[j])
			{
				free(a);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_a_sorted(int *a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (a[i] > a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_number_of_t_nbrs(char *str)
{
	int		i;
	char	**arr;

	arr = ft_split(str);
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!ft_atoi_checker(arr[i]))
		{
			free_split(arr);
			return (0);
		}
		i++;
	}
	free_split(arr);
	return (i);
}
