/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:16:09 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 22:55:53 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
static void	ft_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb < b->nb && current_a->nb < best_match)
			{
				best_match = current_a->nb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// Done
void	ft_init_nodes_a(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}

// Done
void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_b(a, b);
}

// Done
char **ft_new_split(char const *s, char c)
{
	int count;
	char **res;
	int i;

	i = 0;
	count = ft_wordcount(s, c);
	if (!count)
		exit(EXIT_FAILURE);
	res = malloc(sizeof(char *) * (size_t)(count + 2));
	if (!res)
		return (NULL);
	while (count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ; // Wtf is this?
		}
		res[i++] = ft_nextword(s, c);
	}
	res[i] = NULL;
	return (res);
}

// Done
t_stack *ft_find_max(t_stack *stack)
{
	long max;
	t_stack *max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}