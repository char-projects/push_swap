/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 00:23:20 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/13 17:40:08 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"

void	ft_execute(char *str, t_stack **stack_a,
		t_stack **stack_b)
{
	if (ft_strncmp(str, "sa", 2) == 0)
		ft_sa(stack_a, 0);
	else if (ft_strncmp(str, "sb", 2) == 0)
		ft_sb(stack_b, 0);
	else if (ft_strncmp(str, "ss", 2) == 0)
		ft_ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pa", 2) == 0)
		ft_pa(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pb", 2) == 0)
		ft_pb(stack_b, stack_a, 0);
	else if (ft_strncmp(str, "ra", 2) == 0)
		ft_ra(stack_a, 0);
	else if (ft_strncmp(str, "rb", 2) == 0)
		ft_rb(stack_b, 0);
	else if (ft_strncmp(str, "rr", 2) == 0)
		ft_rr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rra", 3) == 0)
		ft_rra(stack_a, 0);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		ft_rrb(stack_b, 0);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		ft_rrr(stack_a, stack_b, 0);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	// Include get next line in the libft repo
	while ((str = get_next_line(0)))
	{
		ft_execute(str, stack_a, stack_b);
		free(str);
	}
	if (ft_is_sorted(*stack_a) && ft_stack_len(*stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int ft_parse_arguments(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	long	nb;

	i = 1;
	while (i < argc)
	{
		if (ft_error(argv[i]))
			ft_free_errors(stack_a);
		nb = ft_atol(argv[i]);
		if (ft_duplicate(*stack_a, nb))
			ft_free_errors(stack_a);
		ft_append_node(stack_a, nb);
		i++;
	}
	return (1);
}
*/
/*
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!ft_parse_arguments(argc, argv, &stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	ft_checker(&stack_a, &stack_b);
}
*/
