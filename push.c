/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:15:10 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 18:24:41 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **dst, t_stack **src)
{
	t_stack	*push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
	if (!*dst)
	{
		*dst = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dst;
		push->next->prev = push;
		*dst = push;
	}
}

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	ft_push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	ft_pb(t_stack **b, t_stack **a, int print)
{
	ft_push(b, a);
	if (print)
		ft_printf("pb\n");
}
