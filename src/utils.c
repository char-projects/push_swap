/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:12:29 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/09 15:28:59 by cschnath         ###   ########.fr       */
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

void	ft_calc_argc(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
		stack->argc = ft_wordcount(argv[1], ' ') + 1;
	else
		stack->argc = argc;
}
