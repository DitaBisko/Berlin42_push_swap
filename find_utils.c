/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 09:10:58 by dbisko            #+#    #+#             */
/*   Updated: 2024/06/30 10:38:25 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack)
{
	t_list	*current;
	t_list	*min;

	current = *stack;
	min = current;
	while (current != NULL)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*find_max(t_list **stack)
{
	t_list	*current;
	t_list	*max;

	current = *stack;
	max = current;
	while (current != NULL)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_list	*find_cheapest(t_list **stack)
{
	t_list	*current;
	t_list	*cheapest;

	current = *stack;
	cheapest = current;
	while (current != NULL)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
