/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:03:04 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 13:07:09 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
bool	ft_is_duplicate(t_stack *stack, long int nb)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->nb == nb)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

// Done
bool	ft_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (false);
		a = a->next;
	}
	return (true);
}

// Done
static int	ft_wordcount(char const *s, char c)
{
	int		count;
	bool	i;

	count = 0;
	while (*s)
	{
		i = false;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (!i)
			{
				count++;
				i = true;
			}
			s++;
		}
	}
	return (count);
}

// Done
static char	*ft_nextword(char *s, char c)
{
	static int	index = 0;
	char		*word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[index] == c)
		index++;
	while (s[index + len] != c && s[index + len])
		len++;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((s[index] != c) && s[index])
		word[i++] = s[index++];
	word[i] = '\0';
	return (word);
}

// Done
char **ft_new_split(char *s, char c)
{
	int count;
	char **res;
	int i;

	i = 0;
	count = ft_wordcount(s, c);
	if (!count)
		exit(EXIT_FAILURE);
	res = malloc(sizeof(char *) * (size_t)(count + 2));
	if (!res)
		return (NULL);
	while (count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ; // Wtf is this?
		}
		res[i++] = ft_nextword(s, c);
	}
	res[i] = NULL;
	return (res);
}
