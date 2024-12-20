/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:22:40 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/19 19:52:36 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This one works for sure
static void	ft_swap(t_stack **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

// Done
void	ft_sa(t_stack **a, bool print)
{
	ft_swap(a);
	if (!print)
		ft_printf("sa\n");
}

// Done
void	ft_sb(t_stack **b, bool print)
{
	ft_swap(b);
	if (!print)
		ft_printf("sb\n");
}

// Done
void	ft_ss(t_stack **a, t_stack **b, bool print)
{
	ft_swap(a);
	ft_swap(b);
	if (!print)
		ft_printf("ss\n");
}