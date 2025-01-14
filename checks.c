/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:04 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/14 19:26:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function checks if the stack is already sorted in ascending order
int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// This function iterates over the stack and checks if any of the nodes are duplicates
int	ft_check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current == runner)
			{
				printf("Duplicate node found: %p\n", (void *)runner);
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

// Count the number of words in the string
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

// Extract the next word from the string
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

// Split the string into words
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
