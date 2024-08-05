/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attributes_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:19:05 by dbisko            #+#    #+#             */
/*   Updated: 2024/07/03 20:55:48 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	t_list	*max_node;
	t_list	*target_node;

	a_node = *stack_a;
	max_node = find_max(stack_b);
	while (a_node != NULL)
	{
		b_node = *stack_b;
		target_node = NULL;
		while (b_node != NULL)
		{
			if (a_node->value > b_node->value && (target_node == NULL
					|| target_node->value < b_node->value))
				target_node = b_node;
			b_node = b_node->next;
		}
		if (target_node == NULL)
			a_node->target = max_node;
		else
			a_node->target = target_node;
		a_node = a_node->next;
	}
}

void	set_target_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*b_node;
	t_list	*a_node;
	t_list	*min_node;
	t_list	*target_node;

	b_node = *stack_b;
	min_node = find_min(stack_a);
	while (b_node != NULL)
	{
		a_node = *stack_a;
		target_node = NULL;
		while (a_node != NULL)
		{
			if (b_node->value < a_node->value && (target_node == NULL
					|| target_node->value > a_node->value))
				target_node = a_node;
			a_node = a_node->next;
		}
		if (target_node == NULL)
			b_node->target = min_node;
		else
			b_node->target = target_node;
		b_node = b_node->next;
	}
}

void	set_current_pos(t_list **stack)
{
	int		pos;
	t_list	*current;

	pos = 0;
	current = *stack;
	while (current != NULL)
	{
		current->index = pos;
		pos++;
		current = current->next;
	}
}
