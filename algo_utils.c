/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:22:30 by dbisko            #+#    #+#             */
/*   Updated: 2024/03/04 15:22:33 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack(t_list **from, t_list **to)
{
	t_list	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	swap_first_two(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	if (first->next != NULL)
		first->next->prev = first;
	second->prev = NULL;
	*stack = second;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*new_first;
	t_list	*last;
	t_list	*old_first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	new_first = *stack;
	old_first = *stack;
	last = *stack;
	while (new_first->next != NULL)
		new_first = new_first->next;
	while (last->next->next != NULL)
		last = last->next;
	last->next = NULL;
	new_first->next = old_first;
	*stack = new_first;
}
