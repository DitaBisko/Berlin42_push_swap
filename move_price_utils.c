/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_price_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:19:05 by dbisko            #+#    #+#             */
/*   Updated: 2024/04/22 11:56:52 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	min_cost(int compare_to, int compare_1, int compare_2, int compare_3)
{
	if (compare_to <= compare_1 && compare_to
		<= compare_2 && compare_to <= compare_3)
		return (true);
	else
		return (false);
}

void	place_price(t_list *node, int move, int price)
{
	node->move_to_make = move;
	node->cost = price;
}
