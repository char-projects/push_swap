/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/05 01:38:40 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(t_stack **a, t_stack **b, char **argv)
{
    if (argv)
        free(argv);
    if (a)
        ft_free_stack(a);
    if (b)
        ft_free_stack(b);
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

long ft_atol(const char *str)
{
    long res;
    int sign;

    res = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + *str - '0';
        str++;
    }
    return (res * sign);
}

t_stack *find_min(t_stack *stack)
{
    t_stack *tmp;
    t_stack *min;

    tmp = stack;
    min = stack;
    while (tmp)
    {
        if (tmp->nb < min->nb)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}