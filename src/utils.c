/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:12:29 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 19:35:37 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_arr(t_stack *arr, int size, int i)
{
	int	j;
	int	temp;

	while (i < size)
	{
		arr->sorted[i] = arr->a[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr->sorted[i] > arr->sorted[j])
			{
				temp = arr->sorted[i];
				arr->sorted[i] = arr->sorted[j];
				arr->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// map each value in a to its target index in sorted
void	ft_set_target(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	stack->target = ft_calloc(stack->size_b + 1, sizeof(int));
	while (i < stack->size_b)
	{
		j = 0;
		while (j < stack->size_a)
		{
			if (stack->a[j] > stack->b[i])
			{
				stack->target[i] = j;
				break ;
			}
			j++;
		}
		if (j == stack->size_a)
			stack->target[i] = stack->size_a + 1;
		i++;
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	return (n);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}
