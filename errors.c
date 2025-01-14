/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:41:03 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/13 20:04:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
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

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	ft_free_errors(t_stack **a)
{
	ft_free_stack(a);
	exit(1);
}
