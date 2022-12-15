#include "push_swap.h"

int ft_atoi_checker(char *str)
{
    int i;

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

void from_bottom_to_top(int *a, int len)
{
    printf("rra\n");
    int i;
    int tmp;
    int tmp2;

    i = 1;
    tmp = a[0];
    a[0] = a[len - 1];
    while (i < len)
    {
        tmp2 = a[i];
        a[i] = tmp;
        tmp = tmp2;
        i++;
    }
}

void from_bottom_to_top_b(int *a, int len)
{
    printf("rrb\n");
    int i;
    int tmp;
    int tmp2;

    i = 1;
    tmp = a[0];
    a[0] = a[len - 1];
    while (i < len)
    {
        tmp2 = a[i];
        a[i] = tmp;
        tmp = tmp2;
        i++;
    }
}

void swap_first_two(int *a)
{
    printf("sa\n");
    int tmp;

    tmp = a[0];
    a[0] = a[1];
    a[1] = tmp;
}

void from_top_to_bottom(int *a, int len)
{
    printf("ra\n");
    int i;
    int tmp;
    int tmp2;

    i = 2;
    tmp = a[len - 1];
    a[len - 1] = a[0];
    while (i <= len)
    {
        tmp2 = a[len - i];
        a[len - i] = tmp;
        tmp = tmp2;
        i++;
    }
}
void from_top_to_bottom_b(int *a, int len)
{
    printf("rb\n");
    int i;
    int tmp;
    int tmp2;

    i = 2;
    tmp = a[len - 1];
    a[len - 1] = a[0];
    while (i <= len)
    {
        tmp2 = a[len - i];
        a[len - i] = tmp;
        tmp = tmp2;
        i++;
    }
}

int *ft_add_to_stack(int *arr, int *len, int to_add)
{
    int *new_arr;
    int i;

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

int *ft_stack_without_first(int *arr, int *len)
{
    int *new_arr;
    int i;

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

void ft_push_b(int **a, int **b, int *a_len, int *b_len)
{
    printf("pb\n");
    int b_new_len;
    int a_new_len;

    b_new_len = *b_len;
    a_new_len = *a_len;
    *b = ft_add_to_stack(*b, &b_new_len, *a[0]);
    *a = ft_stack_without_first(*a, &a_new_len);
    *b_len = b_new_len;
    *a_len = a_new_len;
}

void ft_push_a(int **a, int **b, int *a_len, int *b_len)
{
    printf("pa\n");
    int b_new_len;
    int a_new_len;

    b_new_len = *b_len;
    a_new_len = *a_len;
    *a = ft_add_to_stack(*a, &a_new_len, *b[0]);
    *b = ft_stack_without_first(*b, &b_new_len);
    *b_len = b_new_len;
    *a_len = a_new_len;
}

int ft_number_of_nbrs(char *str)
{
    int i;
    char **arr;

    arr = ft_split(str);
    if (!arr)
        return (0);
    i = 0;
    while (arr[i])
    {
        if (!ft_atoi_checker(arr[i]))
            return (0);
        free(arr[i]);
        i++;
    }
    free(arr);
    return (i);
}

int free_split(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
    return (0);
}

int ft_set_a_2(int *a, int len, char **av)
{
    int i;
    int x;
    int j;
    char **arr;

    i = 0;
    x = 1;
    while (i < len)
    {
        j = 0;
        arr = ft_split(av[x]);
        if (!arr || !ft_number_of_nbrs(av[x]))
            return 0;
        while (arr[j])
        {
            a[i] = atoi(arr[j]);
            i++;
            j++;
        }
        x++;
    }
    return (1);
}

int *ft_set_a(char **av, int *len)
{
    int *a;
    int i;
    int j;
    int x;
    char **arr;
    int oldlen;

    oldlen = *len;
    i = 1;
    while (i <= oldlen)
    {
        if (!ft_number_of_nbrs(av[i]))
            return (0);
        *len += ft_number_of_nbrs(av[i]) - 1;
        i++;
    }
    a = (int *)malloc(sizeof(int) * *len);
    if (!a)
        return (0);
    if (!ft_set_a_2(a, *len, av))
        return (0);
    return (a);
}

int ft_check_dup(int *a, int len)
{
    int i;
    int j;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (a[i] == a[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int min_index(int *a, int len)
{
    int i;
    int indx;

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
int max_index(int *a, int len)
{
    int i;
    int indx;

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

void push_min_to_top(int *a, int len)
{
    int i;
    int j;

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

void push_max_to_top(int *b, int len)
{
    int i;
    int j;

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

int is_a_sorted(int *a, int len)
{
    int i;
    int j;

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

void ft_do_magic(int **a, int *a_len, int **b, int *b_len)
{
    int i;
    int len_holder;
    int len_holder2;

    len_holder = *a_len;
    while (*a_len > 3)
    {
        if (is_a_sorted(*a, *a_len))
            break;
        push_min_to_top(*a, *a_len);
        ft_push_b(a, b, a_len, b_len);
    }
    if (*a_len == 3)
        ft_do_magic_2(*a, *b, 3);
    i = 0;
    len_holder2 = *a_len;
    while (*b_len > 0)
        ft_push_a(a, b, a_len, b_len);
}

void sort_arr(int *arr, int len)
{
    int i;
    int j;
    int tmp;

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

int *sorted_arr(int *arr, int len)
{
    int i;
    int j;
    int *new_arr;

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

int biggest_n_index(int *arr, int len)
{
    int i;
    int indx;

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

int is_it_closer_from_top(int *a, int len, int nb)
{
    int i;
    int j;

    i = 0;
    j = len - 1;
    while (i < len)
    {
        if (a[i] <= nb)
            break;
        i++;
    }
    while (j > 0)
    {
        if (a[j] <= nb)
            break;
        j--;
    }
    if (i <= (len - j))
        return (0);
    else
        return (1);
}

void ft_rr(int *a, int a_len, int *b, int b_len)
{
    printf("rr\n");
    int i;
    int tmp;
    int tmp2;

    i = 2;
    tmp = a[a_len - 1];
    a[a_len - 1] = a[0];
    while (i <= a_len)
    {
        tmp2 = a[a_len - i];
        a[a_len - i] = tmp;
        tmp = tmp2;
        i++;
    }
    i = 2;
    tmp = b[b_len - 1];
    b[b_len - 1] = b[0];
    while (i <= b_len)
    {
        tmp2 = b[b_len - i];
        b[b_len - i] = tmp;
        tmp = tmp2;
        i++;
    }
}

int devide_or_multiply(int nb)
{
    if (nb < 0)
        return (nb / 2);
    return (nb * 2);
}

void ft_do_split(NBR *nbrs, int *sorted_arr, int a_len)
{
    if (a_len <= 150)
    {
        nbrs->y = sorted_arr[a_len / 3];
        nbrs->x = a_len / 3;
    }
    else if (a_len <= 200)
    {
        nbrs->y = sorted_arr[a_len / 4];
        nbrs->x = a_len / 4;
    }
    else if (a_len <= 300)
    {
        nbrs->y = sorted_arr[a_len / 5];
        nbrs->x = a_len / 5;
    }
    else if (a_len <= 400)
    {
        nbrs->y = sorted_arr[a_len / 6];
        nbrs->x = a_len / 6;
    }
    else
    {
        nbrs->y = sorted_arr[a_len / 7];
        nbrs->x = a_len / 7;
    }
    nbrs->i = sorted_arr[(nbrs->x / 2) + 1];
}

void do_magic_part2(int **a, int *a_len, int **b, int *b_len)
{
    ft_do_magic_2(*a, *b, *a_len);
    while (*b_len > 0)
    {
        push_max_to_top(*b, *b_len);
        ft_push_a(a, b, a_len, b_len);
    }
}

void ft_do_magic_5(int **a, int *a_len, int **b, int *b_len)
{
    NBR nbrs;

    while (*a_len > 3)
    {
        nbrs.sorted_a = sorted_arr(*a, *a_len);
        ft_do_split(&nbrs, nbrs.sorted_a, *a_len);
        if (is_a_sorted(*a, *a_len))
            break;
        while (nbrs.x >= 0)
        {
            if (*a[0] <= nbrs.y)
            {
                ft_push_b(a, b, a_len, b_len);
                if (*b[0] < nbrs.i && !is_it_closer_from_top(*a, *a_len, nbrs.y) && *a[0] > nbrs.y)
                    ft_rr(*a, *a_len, *b, *b_len);
                else if (*b[0] < nbrs.i)
                    from_top_to_bottom_b(*b, *b_len);
                nbrs.x--;
            }
            else
                from_top_to_bottom(*a, *a_len);
        }
    }
}

int main(int ac, char **av)
{
    int len;
    int b_len;
    int *a;
    int *b;
    int i;

    len = ac - 1;
    b_len = 0;
    a = ft_set_a(av, &len);
    if (!a || ft_check_dup(a, len) || len == 0)
    {
        printf("error!");
        return (0);
    }
    b = (int *)malloc(sizeof(int));
    if (!a)
    {
        printf("error!");
        return (0);
    }
    if (is_a_sorted(a, len))
    {
        printf("already sorted!");
        return (0);
    }
    if (len <= 3)
    {
        ft_do_magic_2(a, b, len);
        return (0);
    }
    if (len < 25)
    {
        ft_do_magic(&a, &len, &b, &b_len);
        return (0);
    }
    ft_do_magic_5(&a, &len, &b, &b_len);
    do_magic_part2(&a, &len, &b, &b_len);

    printf("a[0] == %i\n", a[0]);
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
}