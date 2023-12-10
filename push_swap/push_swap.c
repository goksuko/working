#include "push_swap.h"

void    push_swap(t_stack *a, t_stack *b)
{
    int     i;
    int     j;
    int     len;

    i = 0;
    j = 0;
    len = a->len;
    if (is_sorted(a))
        return ;
    if (len == 2)
        swap(a, 'a');
    else if (len == 3)
        sort_three(a);
    else if (len == 4)
        sort_four(a, b);
    else if (len == 5)
        sort_five(a, b);
    else
        sort_hundred(a, b);
}

// Path: working/push_swap/sort_hundred.c
void    sort_hundred(t_stack *a, t_stack *b)
{
    int     i;
    int     j;
    int     len;
    int     min;
    int     max;

    i = 0;
    j = 0;
    len = a->len;
    min = find_min(a);
    max = find_max(a);
    while (i < len)
    {
        if (a->arr[0] == min || a->arr[0] == max)
            push(b, a, 'b');
        else
            rotate(a, 'a');
        i++;
    }
    sort_three(a);
    while (j < len - 3)
    {
        push(a, b, 'a');
        j++;
    }
    while (b->len > 0)
    {
        if (b->arr[0] > a->arr[0])
            rotate(a, 'a');
        else
            push(a, b, 'a');
    }
}

// Path: working/push_swap/sort_five.c
void    sort_five(t_stack *a, t_stack *b)
{
    int     i;
    int     j;
    int     len;
    int     min;
    int     max;

    i = 0;
    j = 0;
    len = a->len;
    min = find_min(a);
    max = find_max(a);
    while (i < len)
    {
        if (a->arr[0] == min || a->arr[0] == max)
            push(b, a, 'b');
        else
            rotate(a, 'a');
        i++;
    }
    sort_three(a);
    while (j < len - 3)
    {
        push(a, b, 'a');
        j++;
    }
    while (b->len > 0)
    {
        if (b->arr[0] > a->arr[0])
            rotate(a, 'a');
        else
            push(a, b, 'a');
    }
}

// Path: working/push_swap/sort_four.c
void    sort_four(t_stack *a, t_stack *b)
{
    int     i;
    int     j;
    int     len;
    int     min;
    int     max;

    i = 0;
    j = 0;
    len = a->len;
    min = find_min(a);
    max = find_max(a);
    while (i < len)
    {
        if (a->arr[0] == min || a->arr[0] == max)
            push(b, a, 'b');
        else
            rotate(a, 'a');
        i++;
    }
    sort_three(a);
    while (j < len - 3)
    {
        push(a, b, 'a');
        j++;
    }
    while (b->len > 0)
    {
        if (b->arr[0] > a->arr[0])
            rotate(a, 'a');
        else
            push(a, b, 'a');
    }
}

// Path: working/push_swap/sort_three.c
void    sort_three(t_stack *a)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    while (i < len)
    {
        if (a->arr[0] > a->arr[1])
            swap(a, 'a');
        else if (a->arr[0] > a->arr[2])
            rrotate(a, 'a');
        else if (a->arr[0] < a->arr[2] && a->arr[1] > a->arr[2])
            rotate(a, 'a');
        i++;
    }
}

// Path: working/push_swap/utils.c
int     is_sorted(t_stack *a)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    while (i < len - 1)
    {
        if (a->arr[i] > a->arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

// Path: working/push_swap/utils2.c
int     find_min(t_stack *a)
{
    int     i;
    int     len;
    int     min;

    i = 0;
    len = a->len;
    min = a->arr[0];
    while (i < len)
    {
        if (a->arr[i] < min)
            min = a->arr[i];
        i++;
    }
    return (min);
}

// Path: working/push_swap/utils2.c
int     find_max(t_stack *a)
{
    int     i;
    int     len;
    int     max;

    i = 0;
    len = a->len;
    max = a->arr[0];
    while (i < len)
    {
        if (a->arr[i] > max)
            max = a->arr[i];
        i++;
    }
    return (max);
}

// Path: working/push_swap/utils2.c
int     find_index(t_stack *a, int num)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    while (i < len)
    {
        if (a->arr[i] == num)
            return (i);
        i++;
    }
    return (-1);
}

// Path: working/push_swap/utils2.c
int     find_median(t_stack *a)
{
    int     i;
    int     j;
    int     len;
    int     median;
    int     *arr;

    i = 0;
    j = 0;
    len = a->len;
    arr = (int *)malloc(sizeof(int) * len);
    while (i < len)
    {
        arr[i] = a->arr[i];
        i++;
    }
    sort_arr(arr, len);
    median = arr[len / 2];
    free(arr);
    return (median);
}

// Path: working/push_swap/utils2.c
void    sort_arr(int *arr, int len)
{
    int     i;
    int     j;
    int     temp;

    i = 0;
    j = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            j++;
        }
        i++;
    }
}

// Path: working/push_swap/utils2.c
int     find_closest(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_top(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_top_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_top(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_top_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_bottom(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_bottom_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) < abs(closest - num))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_bottom(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_bottom_index(t_stack *a, int num)
{
    int     i;
    int     len;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - num) > abs(farthest - num))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_median(t_stack *a)
{
    int     i;
    int     len;
    int     median;
    int     closest;

    i = 0;
    len = a->len;
    median = find_median(a);
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - median) < abs(closest - median))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_median_index(t_stack *a)
{
    int     i;
    int     len;
    int     median;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    median = find_median(a);
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - median) < abs(closest - median))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_median(t_stack *a)
{
    int     i;
    int     len;
    int     median;
    int     farthest;

    i = 0;
    len = a->len;
    median = find_median(a);
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - median) > abs(farthest - median))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_median_index(t_stack *a)
{
    int     i;
    int     len;
    int     median;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    median = find_median(a);
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - median) > abs(farthest - median))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_min(t_stack *a)
{
    int     i;
    int     len;
    int     min;
    int     closest;

    i = 0;
    len = a->len;
    min = find_min(a);
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - min) < abs(closest - min))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_min_index(t_stack *a)
{
    int     i;
    int     len;
    int     min;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    min = find_min(a);
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - min) < abs(closest - min))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_min(t_stack *a)
{
    int     i;
    int     len;
    int     min;
    int     farthest;

    i = 0;
    len = a->len;
    min = find_min(a);
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - min) > abs(farthest - min))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_min_index(t_stack *a)
{
    int     i;
    int     len;
    int     min;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    min = find_min(a);
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - min) > abs(farthest - min))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_max(t_stack *a)
{
    int     i;
    int     len;
    int     max;
    int     closest;

    i = 0;
    len = a->len;
    max = find_max(a);
    closest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - max) < abs(closest - max))
            closest = a->arr[i];
        i++;
    }
    return (closest);
}

// Path: working/push_swap/utils2.c
int     find_closest_to_max_index(t_stack *a)
{
    int     i;
    int     len;
    int     max;
    int     closest;
    int     index;

    i = 0;
    len = a->len;
    max = find_max(a);
    closest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - max) < abs(closest - max))
        {
            closest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_max(t_stack *a)
{
    int     i;
    int     len;
    int     max;
    int     farthest;

    i = 0;
    len = a->len;
    max = find_max(a);
    farthest = a->arr[0];
    while (i < len)
    {
        if (abs(a->arr[i] - max) > abs(farthest - max))
            farthest = a->arr[i];
        i++;
    }
    return (farthest);
}

// Path: working/push_swap/utils2.c
int     find_farthest_from_max_index(t_stack *a)
{
    int     i;
    int     len;
    int     max;
    int     farthest;
    int     index;

    i = 0;
    len = a->len;
    max = find_max(a);
    farthest = a->arr[0];
    index = 0;
    while (i < len)
    {
        if (abs(a->arr[i] - max) > abs(farthest - max))
        {
            farthest = a->arr[i];
            index = i;
        }
        i++;
    }
    return (index);
}

// Path: working/push_swap/utils2.c
void    print_arr(int *arr, int len)
{
    int     i;

    i = 0;
    while (i < len)
    {
        printf("%d\n", arr[i]);
        i++;
    }
}

// Path: working/push_swap/utils2.c
void    print_stack(t_stack *a)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    while (i < len)
    {
        printf("%d\n", a->arr[i]);
        i++;
    }
}

// Path: working/push_swap/utils2.c
void    print_stacks(t_stack *a, t_stack *b)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    printf("Stack A:\n");
    while (i < len)
    {
        printf("%d\n", a->arr[i]);
        i++;
    }
    i = 0;
    len = b->len;
    printf("Stack B:\n");
    while (i < len)
    {
        printf("%d\n", b->arr[i]);
        i++;
    }
}

// Path: working/push_swap/utils2.c
void    print_stacks_color(t_stack *a, t_stack *b)
{
    int     i;
    int     len;

    i = 0;
    len = a->len;
    printf("Stack A:\n");
    while (i < len)
    {
        printf("\033[0;31m%d\033[0m\n", a->arr[i]);
        i++;
    }
    i = 0;
    len = b->len;
    printf("Stack B:\n");
    while (i < len)
    {
        printf("\033[0;32m%d\033[0m\n", b->arr[i]);
        i++;
    }
}

int    main(int argc, char **argv)
{
    t_stack     *a;
    t_stack     *b;

    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a->arr = (int *)malloc(sizeof(int) * argc - 1);
    b->arr = (int *)malloc(sizeof(int) * argc - 1);
    a->len = argc - 1;
    b->len = 0;
    if (argc == 1)
        return (0);
    if (!is_valid(argv))
    {
        printf("Error\n");
        return (0);
    }
    fill_stack(a, argv);
    push_swap(a, b);
    free(a->arr);
    free(b->arr);
    free(a);
    free(b);
    return (0);
}