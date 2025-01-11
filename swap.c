/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:22:40 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 21:49:21 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **upper)
{
	if (!*upper || !(*upper)->next)
		return ;
	*upper = (*upper)->next;
	(*upper)->prev->prev = *upper;
	(*upper)->prev->next = (*upper)->next;
	if ((*upper)->next)
		(*upper)->next->prev = (*upper)->prev;
	(*upper)->next = (*upper)->prev;
	(*upper)->prev = NULL;
}

void	ft_sa(t_stack **a, int print)
{
	ft_swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	ft_sb(t_stack **b, int print)
{
	ft_swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_swap(a);
	ft_swap(b);
	if (!print)
		ft_printf("ss\n");
}
