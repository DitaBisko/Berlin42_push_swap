/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:32:46 by dbisko            #+#    #+#             */
/*   Updated: 2024/03/04 15:46:25 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_attributes_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	set_stk_size(stack_a);
	set_stk_size(stack_b);
	set_current_pos(stack_a);
	set_current_pos(stack_b);
	set_above_med(stack_a);
	set_above_med(stack_b);
	set_target_a(stack_a, stack_b);
	current = *stack_a;
	while (current != NULL)
	{
		move_price(current);
		current = current->next;
	}
}

void	set_attributes_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*current;

	set_stk_size(stack_a);
	set_stk_size(stack_b);
	set_current_pos(stack_a);
	set_current_pos(stack_b);
	set_above_med(stack_a);
	set_above_med(stack_b);
	set_target_b(stack_b, stack_a);
	current = *stack_b;
	while (current != NULL)
	{
		move_price(current);
		current = current->next;
	}
}

int	stack_size(t_list **stack)
{
	int		count;
	t_list	*current;

	current = *stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	set_stk_size(t_list **stack)
{
	int		stk_size;
	t_list	*current;

	stk_size = stack_size(stack);
	current = *stack;
	while (current != NULL)
	{
		current->stk_len = stk_size;
		current = current->next;
	}
}

void	set_above_med(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->index == 0)
			current->above_median = true;
		else if (current->index <= (current->stk_len / 2))
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
	}
}
