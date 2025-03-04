/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:47 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/09 16:25:38 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_check_max_int(char **argv, int flag)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
		{
			ft_printf("Error: Overflow!\n");
			if (flag)
				ft_charppfree(argv);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_free_errors(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->sorted);
	free(stack);
	exit(EXIT_FAILURE);
}

int	ft_error(char *argv)
{
	if (*argv == '+' || *argv == '-')
		argv++;
	if (!ft_isdigit(*argv))
	{
		ft_printf("Error: Formatting!\n");
		return (1);
	}
	while (*argv)
	{
		if (!ft_isdigit(*argv))
		{
			ft_printf("Error: Formatting!\n");
			return (1);
		}
		argv++;
	}
	return (0);
}

// This function checks if any of the argvs are duplicates
int	ft_duplicate(char **argv, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error: Duplicate!\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
