/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:41:03 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 22:05:59 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	}
	return (0);
}

int	ft_duplicate(t_stack *a, int nb)
{
	while (a)
	{
		if (a->nb == nb)
			return (1);
		a = a->next;
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
	ft_printf("Error\n");
	exit(1);
}
