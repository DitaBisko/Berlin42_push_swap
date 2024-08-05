/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_price.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:11:02 by dbisko            #+#    #+#             */
/*   Updated: 2024/07/04 08:57:15 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	both_up_cal(t_list *node)
{
	if (node->index >= node->target->index)
		return (node->index);
	else
		return (node->target->index);
}

int	both_down_cal(t_list *node)
{
	if ((node->stk_len - node->index)
		>= (node->target->stk_len - node->target->index))
		return (node->stk_len - node->index);
	else
		return (node->target->stk_len - node->target->index);
}

int	node_up_target_down_cal(t_list *node)
{
	return (node->index + (node->target->stk_len - node->target->index));
}

int	node_down_target_up_cal(t_list *node)
{
	return ((node->stk_len - node->index) + node->target->index);
}

// 1 = both up, 2 = both down,
// 3 = node up, target down, 4 = node down, target down
void	move_price(t_list *node)
{
	int	both_up;
	int	both_down;
	int	node_up_target_down;
	int	node_down_target_up;

	both_up = both_up_cal(node);
	both_down = both_down_cal(node);
	node_up_target_down = node_up_target_down_cal(node);
	node_down_target_up = node_down_target_up_cal(node);
	if (min_cost(both_up, both_down, node_up_target_down, node_down_target_up))
		place_price(node, 1, both_up);
	else if (min_cost(both_down, both_up,
			node_up_target_down, node_down_target_up))
		place_price(node, 2, both_down);
	else if (min_cost(node_up_target_down, both_up,
			both_down, node_down_target_up))
		place_price(node, 3, node_up_target_down);
	else
		place_price(node, 4, node_down_target_up);
}
