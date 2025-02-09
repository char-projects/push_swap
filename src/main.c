/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:53 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/09 15:46:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_validate(char **argv, t_stack *stack)
{
	int		i;
	long	nb;

	i = 1;
	while (i < stack->argc)
	{
		if (ft_error(argv[i]))
			ft_free_errors(stack);
		nb = ft_atol(argv[i]);
		stack->a[i - 1] = nb;
		i++;
	}
	stack->og_size = stack->argc - 1;
	stack->size_a = stack->argc - 1;
	stack->size_b = 0;
}

void	ft_split_stacks(char **argv, t_stack *stack)
{
	char	**split_argv;
	char	**new_argv;
	int		i;

	i = 0;
	split_argv = ft_new_split(argv[1], ' ');
	ft_check_max_int(split_argv);
	new_argv = ft_calloc((stack->argc + 2), sizeof(char *));
	if (!new_argv)
		exit(EXIT_FAILURE);
	new_argv[0] = ft_strdup(argv[0]);
	while (i < stack->argc - 1)
	{
		new_argv[i + 1] = ft_strdup(split_argv[i]);
		i++;
	}
	new_argv[stack->argc + 1] = NULL;
	ft_charppfree(split_argv);
	if (ft_duplicate(new_argv, stack->argc))
	{
		ft_charppfree(new_argv);
		ft_free_errors(stack);
	}
	ft_validate(new_argv, stack);
	ft_charppfree(new_argv);
}

void	ft_init_stacks(char **argv, t_stack *stack)
{
	ft_check_max_int(argv);
	if (ft_duplicate(argv, stack->argc))
		ft_free_errors(stack);
	ft_validate(argv, stack);
}

t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	ft_calc_argc(stack, argc, argv);
	stack->a = ft_calloc(stack->argc, sizeof(int));
	stack->b = ft_calloc(stack->argc, sizeof(int));
	stack->sorted = ft_calloc(stack->argc, sizeof(int));
	if (stack->argc < 2 || (stack->argc == 2 && !(*argv)[1]))
	{
		ft_printf("Error: Number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		ft_split_stacks(argv, stack);
	else
		ft_init_stacks(argv, stack);
	return (stack);
}

/* Add this for eval:
ft_printf("Result: ");
ft_print_arr(stack->a, stack->size_a); */

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		cheapest;

	stack = ft_init(argc, argv);
	if (ft_is_sorted(stack->a, stack->size_a))
		ft_free_errors(stack);
	else
	{
		ft_sort_arr(stack, stack->size_a, 0);
		if (stack->size_a <= 3)
			ft_small(stack, stack->size_a);
		else
		{
			ft_initial_push(stack);
			while (stack->size_b > 0)
			{
				cheapest = ft_cheapest(stack, 0);
				ft_payday(stack, cheapest);
			}
			ft_last_rra(stack);
		}
	}
	ft_free_errors(stack);
}
