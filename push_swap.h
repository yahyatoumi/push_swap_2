#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct t_nbrs
{
	int	x;
	int	i;
	int	y;
	int	*sorted_a;
}	t_nbr;

int			ft_print(char *str);
char		**ft_split(char *str);
int			ft_atoi_checker(char *str);
void		ft_do_magic_2(int *a, int *b, int len);
void		ft_do_magic(int **a, int *a_len, int **b, int *b_len);
int			is_a_sorted(int *a, int len);
void		push_min_to_top(int *a, int len);
int			min_index(int *a, int len);
int			max_index(int *a, int len);
int			ft_check_dup(int *a, int len);
int			*ft_set_a(char **av, int *len);
int			ft_number_of_t_nbrs(char *str);
void		ft_push_a(int **a, int **b, int *a_len, int *b_len);
void		ft_push_b(int **a, int **b, int *a_len, int *b_len);
int			*ft_stack_without_first(int *arr, int *len);
int			*ft_add_to_stack(int *arr, int *len, int to_add);
void		from_top_to_bottom(int *a, int len);
void		swap_first_two(int *a);
void		from_bottom_to_top(int *a, int len);
int			ft_atoi_checker(char *str);
void		fre_aandb(int *a, int *b);
void		free_split(char **arr);
int			devide_or_multiply(int nb);
void		set_x_y(t_nbr *t_nbrs, int *sorted_arr, int a_len, int devider);
int			biggest_n_index(int *arr, int len);
int			is_it_closer_from_top(int *a, int len, int nb);
void		push_max_to_top(int *b, int len);
void		from_bottom_to_top_b(int *a, int len);
void		from_top_to_bottom_b(int *a, int len);
long long	ft_atoi(const char *str);
void		ft_rr(int *a, int a_len, int *b, int b_len);

#endif
