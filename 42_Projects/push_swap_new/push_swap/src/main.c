/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:53 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:58:47 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_validate(char **argv, t_stack *data)
{
	int		i;
	long	nb;

	i = 1;
	while (i < data->argc)
	{
		if (ft_error(argv[i]))
			ft_free_errors(data);
		nb = ft_atol(argv[i]);
		data->a[i - 1] = nb;
		i++;
	}
	data->size_a = data->argc - 1;
	data->size_b = 0;
}

void	ft_init_stacks(char **argv, t_stack *data)
{
	char	**split_argv;
	char	**new_argv;
	int		i;

	i = 0;
	if (data->argc == 2)
	{
		data->argc = ft_wordcount(argv[1], ' ') + 1;
		split_argv = ft_new_split(argv[1], ' ');
		new_argv = malloc((data->argc) * sizeof(char *) + 1);
		if (!new_argv)
			exit(EXIT_FAILURE);
		new_argv[0] = argv[0];
		while (i < data->argc)
		{
			new_argv[i + 1] = split_argv[i];
			i++;
		}
		new_argv[data->argc + 1] = NULL;
		if (ft_duplicate(new_argv, data->argc))
			exit(EXIT_FAILURE);
		ft_validate(new_argv, data);
		free(new_argv);
	}
	else
	{
		if (ft_duplicate(argv, data->argc))
			exit(EXIT_FAILURE);
		ft_validate(argv, data);
	}
}

void	ft_print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	stack->argc = argc;
	stack->a = ft_calloc(stack->argc, sizeof(int));
	stack->b = ft_calloc(stack->argc, sizeof(int));
	stack->sorted = ft_calloc(stack->argc, sizeof(int));
	stack->target_a = ft_calloc(stack->argc, sizeof(int));
	stack->target_b = ft_calloc(stack->argc, sizeof(int));
	if (stack->argc < 2 || (stack->argc == 2 && !(*argv)[1]))
	{
		ft_printf("Error: Number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	ft_init_stacks(argv, stack);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
    int cheapest;

	stack = ft_init(argc, argv);
	if (ft_is_sorted(stack->a, stack->size_a))
		ft_free_errors(stack);
	else
	{
		ft_sort_arr(stack, stack->size_a);
		ft_set_target_a(stack);
		ft_printf("sorted array: ");
		ft_print_arr(stack->sorted, stack->size_a);
		ft_printf("initial target positions: ");
		ft_print_arr(stack->target_a, stack->size_a);
		if (stack->size_a <= 3)
			ft_small(stack, stack->size_a);
		else
		{
			ft_initial_push(stack);
			ft_printf("Stack A after initial push: ");
			ft_print_arr(stack->a, stack->size_a);
			ft_printf("Stack B after initial push: ");
			ft_print_arr(stack->b, stack->size_b);
			while (stack->size_b > 0)
			{
				cheapest = ft_cheapest(stack);
				ft_printf("Cheapest index: %d\n", cheapest);
				ft_printf("Cheapest element: %d\n", stack->b[cheapest]);
    			ft_payday(stack, cheapest);
			}
			ft_printf("Stack A after cost algorithm: ");
			ft_print_arr(stack->a, stack->size_a);
			ft_printf("Stack B after cost algorithm: ");
			ft_print_arr(stack->b, stack->size_b);
		}
	}
	ft_printf("Result: ");
	ft_print_arr(stack->a, stack->size_a);
}
