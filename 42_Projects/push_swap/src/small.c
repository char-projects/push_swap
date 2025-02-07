/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:12:20 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 16:23:39 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->b[0];
	b = stack->b[1];
	c = stack->b[2];
	if (a < b && b < c && a < c)
	{
		ft_sb(stack);
		ft_rrb(stack, 1);
	}
	else if (a < b && b > c && a < c)
		ft_rb(stack, 1);
	else if (a > b && b < c && a > c)
	{
		ft_rrb(stack, 1);
		ft_sb(stack);
	}
	else if (a > b && b < c && a < c)
		ft_rrb(stack, 1);
	else if (a < b && b > c && a > c)
		ft_sb(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && a < c)
		ft_sa(stack);
	else if (a > b && b > c)
	{
		ft_sa(stack);
		ft_rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		ft_sa(stack);
		ft_ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		ft_rra(stack, 1);
}

void	ft_sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
		ft_printf("sa\n");
	}
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
		ft_printf("sb\n");
	}
}

void	ft_small(t_stack *stack, int size)
{
	if (size <= 1)
		return ;
	else if (size == 2)
		ft_sa(stack);
	else
		ft_sort_three(stack);
}
