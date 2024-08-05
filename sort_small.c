/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:25:18 by dbisko            #+#    #+#             */
/*   Updated: 2024/03/02 19:35:51 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	if (!is_sorted(stack))
	{
		if ((*stack)->value > (*stack)->next->value)
		{
			if ((*stack)->next->value < (*stack)->next->next->value
				&& (*stack)->value > (*stack)->next->next->value)
				perform_rot(stack, 1, 'a');
			else if ((*stack)->next->next->value < (*stack)->next->value)
			{
				perform_swap(stack, 'a');
				perform_rev_rot(stack, 1, 'a');
			}
			else
				perform_swap(stack, 'a');
		}
		else if ((*stack)->value < (*stack)->next->value
			&& (*stack)->value < (*stack)->next->next->value)
		{
			perform_rev_rot(stack, 1, 'a');
			perform_swap(stack, 'a');
		}
		else if ((*stack)->value > (*stack)->next->next->value)
			perform_rev_rot(stack, 1, 'a');
	}
}
