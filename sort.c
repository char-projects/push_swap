/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/19 19:32:36 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This one works for sure
void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = ft_find_max(*a);
	if (biggest == *a)
		ft_ra(a, false);
	else if ((*a)->next == biggest)
		ft_rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, false);
}

// Done
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

// Done
int	ft_stack_len(t_stack *stack)
{
	int		len;
	
	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
