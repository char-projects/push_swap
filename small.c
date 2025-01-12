/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:11:37 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/13 00:01:41 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	if ((*stack)->nb > (*stack)->next->nb)
		ft_sa(stack, 1);
}

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

void	ft_push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
    int    position;
    int len;
    
	len = ft_stack_len(*stack_a);
    smallest = ft_find_min(*stack_a);
    position = ft_find_position(*stack_a, smallest->nb);
    if (position <= len / 2)
    {
        while (position-- > 0)
            ft_ra(stack_a, 1);
    }
    else
    {
        while (position++ < len)
            ft_rra(stack_a, 1);
    }
    ft_pb(stack_b, stack_a, 1);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_smallest_to_b(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b, 1);
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
		ft_sort_two(stack_a);
	else if (size == 3)
		ft_sort_three(stack_a);
    else if (size == 4)
        ft_sort_four(stack_a, stack_b);
	else
		ft_sort_five(stack_a, stack_b);
}