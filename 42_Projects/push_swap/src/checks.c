/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:34 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 16:17:55 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rev_sort_b(t_stack *stack, int size)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < size)
	{
		if (stack->b[i] < stack->b[i + 1])
			flag++;
		i++;
	}
	if (flag != 0 && size == 2)
	{
		ft_sb(stack);
		flag = 0;
	}
	if (flag != 0 && size == 3)
	{
		ft_rev_sort_three(stack);
		flag = 0;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	ft_is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_nextword(char const **s, char c)
{
	const char	*start;
	char		*word;
	int			len;

	while (**s == c)
		(*s)++;
	len = 0;
	start = *s;
	while (**s != c && **s)
	{
		len++;
		(*s)++;
	}
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**ft_new_split(char const *s, char c)
{
	int		words;
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = ft_nextword(&s, c);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
