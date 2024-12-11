/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:41:03 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 12:44:20 by cschnath         ###   ########.fr       */
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
int ft_error_duplicate(t_stack *a, int nb)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nb == nb)
            return (1);
        a = a->next;
    }
    return (0);
}

// Done
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nb = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Done
void ft_free_errors(t_stack **a)
{
	ft_free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
