/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 13:31:44 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ft_ra(a, false);
	else if ((*a)->next == biggest)
		ft_rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, false);
}

void	ft_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	ft_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_find_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !(cheapest->target_node->above_median))
		ft_rev_rotate_both(a, b, cheapest);
	ft_prep_for_push(b, cheapest, 'a');
	ft_prep_for_push(a, cheapest->target_node, 'b');
	ft_pb(b, a, false);
}

static void	ft_push_to_a(t_stack **a, t_stack **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	ft_pa(a, b, false);
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	if (len_a-- < 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	if (len_a-- < 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	while (len_a-- > 3 && !ft_is_sorted(*a))
	{
		ft_init_a(*a, *b);
		ft_push_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_b(*a, *b);
		ft_push_to_a(a, b);
	}
	ft_index(*a);
	ft_min_on_top(a);
}
