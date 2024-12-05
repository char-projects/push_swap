/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/05 01:39:41 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_stack **a)
{
    t_stack *biggest;
    
    biggest = find_max(*a);
    if (biggest == *a)
        ft_ra(a, false);
    else if ((*a)->next == biggest)
        ft_rra(a, false);
    if ((*a)->nb > (*a)->next->nb)
        ft_sa(a, false);
}

void ft_sort_stacks(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    t_stack *min;
    t_stack *max;
    int i;
    
    i = 0;
    while (i < 3)
    {
        tmp = *a;
        min = find_min(*a);
        max = find_max(*a);
        while (tmp)
        {
            if (tmp->nb == min->nb)
                tmp->target_node = max;
            else if (tmp->nb == max->nb)
                tmp->target_node = min;
            else
                tmp->target_node = find_target(tmp, *a);
            tmp = tmp->next;
        }
        i++;
    }
    ft_push_to_b(a, b);
}