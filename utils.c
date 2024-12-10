/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 22:27:12 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
int ft_error(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || ft_isdigit(*argv)))
		return (1);
	if ((*argv == '+' || *argv == '-') && !ft_isdigit(argv[1]))
		return (1);
	while (*argv++)
	{
		if (!ft_isdigit(*argv))
			return (1);
	}
	return (0);
}

// Done
long	ft_atol(const char *str)
{
	long	res;
	int		sign;

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

// Done
t_stack	*ft_find_min(t_stack *stack)
{
	long min;
	t_stack *min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

// Done
static void	ft_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		current_b = b;
		best_match = LONG_MIN;
		while (current_b)
		{
			if (current_b->nb < a->nb && current_b->nb > best_match)
			{
				best_match = current_b->nb;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = ft_find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

// Done
static void	ft_cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_b - (a->index);
		if (!(a->target_node->above_median))
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
