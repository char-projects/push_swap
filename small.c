/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:11:37 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 22:35:47 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_swap(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    ft_sa(stack, 1);
}

void	ft_small_rotate(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    ft_ra(stack, 1);
}

void	ft_small_rev_rotate(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    ft_rra(stack, 1);
}

void	ft_insertion_sort(t_stack **a, t_stack **b)
{
	while (*a)
        ft_pb(b, a, 1);
    while (*b)
    {
        if ((*b)->next && (*b)->nb < (*b)->next->nb)
            ft_small_swap(b);
        ft_pa(a, b, 1);
    }
    while (*a && (*a)->next && (*a)->nb > (*a)->next->nb)
    {
        ft_small_swap(a);
        ft_small_rotate(a);
    }
}
