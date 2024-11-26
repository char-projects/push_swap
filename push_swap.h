/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:30:31 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/23 01:30:31 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Include ft_atof in the libft repo 
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Using the Turk algorithm
// Pushes the first two nodes from stack a to stack b without checking anything
// But: There have to be 3 nodes left in stack a
// So if a > 3, push a to b until a = 3, sorting b in descending order
// Now we have a min and max value in stack b
// Look for target nodes next, every a node needs one from b
// A target node is the closest smaller number to the a node
// Then we push that a node on top of its target node in b
// If no closest smaller number is found, the target node is the max value in b
// Cost analysis: Which a node is the cheapest to push to b
// Push cost = (x operations to bring a on top) + (x operations to bring a->target node on top)
// If multiple nodes have the same cost, go with the first one
// Then push every b node back to a
// Every b node needs a target node in a which is the closest bigger number
// If no closest bigger number is found, the target node is the min value in a
// Median: If target node above, do ra, if below do rra
// Finally, find min, if above median, do ra, if below do rra

# include "libft/include/libft.h"

typedef struct s_stack
{
    int data;
    struct s_stack *next;
} t_stack;

// why is this not getting pushed to the repo

#endif
