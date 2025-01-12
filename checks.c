/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:04 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 22:02:50 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicate(t_stack *stack, long int nb)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// Count the number of words in the string
static int	ft_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

// Extract the next word from the string
static char	*ft_nextword(char const **s, char c)
{
	char	*word;
	int		len;
	int		i;

	while (**s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] != c && (*s)[len])
		len++;
	word = malloc((size_t)(len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[len] = '\0';
	*s += len;
	return (word);
}

// Split the string into words
char	**ft_new_split(char const *s, char c)
{
	int		words;
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	res = malloc((size_t)(words + 1) * sizeof(char *));
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
