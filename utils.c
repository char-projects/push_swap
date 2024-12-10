/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 13:31:26 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **a, t_stack **b, char **argv)
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

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

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

static void	ft_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		current_b = b;
		best_match = INT_MAX;
		while (current_b)
		{
			best_match = LONG_MIN;
			current_b = b;
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
}

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
