/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcharpp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:17:58 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/09 16:05:50 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_printcharpp(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}
