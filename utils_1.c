/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:04 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/02 14:00:22 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool ft_is_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

bool ft_is_duplicate(t_stack *stack, long int nb)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        if (tmp->nb == nb)
            return (true);
        tmp = tmp->next;
    }
    return (false);
}

bool ft_is_sorted(t_stack *a)
{
    t_stack *tmp;

    tmp = a;
    while (tmp->next)
    {
        if (tmp->nb > tmp->next->nb)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

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

void ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}