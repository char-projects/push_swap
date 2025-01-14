/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:11:37 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/13 19:07:22 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nb;
	b = (*stack)->next->nb;
	c = (*stack)->next->next->nb;
	if (a > b && b < c && a < c)
		ft_sa(stack, 1);
	else if (a > b && b > c)
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack, 1);
		ft_ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack, 1);
}


void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	// If the first three numbers are sorted in ascending order, do an rra
	if ((*stack_a)->nb < (*stack_a)->next->nb && (*stack_a)->next->nb < (*stack_a)->next->next->nb)
		ft_rra(stack_a, 1);
	else
	{
		ft_push_smallest_to_b(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_a, stack_b, 1);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_smallest_to_b(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b, 1);
}

void	ft_small(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size <= 1)
        return ;
    else if (size == 2)
		ft_sa(stack_a, 1);
	else if (size == 3)
		ft_sort_three(stack_a);
    else if (size == 4)
        ft_sort_four(stack_a, stack_b);
	else
		ft_sort_five(stack_a, stack_b);
}