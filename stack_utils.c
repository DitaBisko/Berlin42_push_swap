/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:17:24 by dbisko            #+#    #+#             */
/*   Updated: 2024/02/28 18:16:09 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

t_bool	add_to_stack(int num, t_list **stack)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list *) malloc(sizeof (t_list));
	if (!new_node)
		return (false);
	new_node->value = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return (true);
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	return (true);
}

void	free_stack(t_list **stack)
{
	t_list	*current_to_free;
	t_list	*next_to_free;

	current_to_free = *stack;
	while (current_to_free != NULL)
	{
		next_to_free = current_to_free->next;
		free(current_to_free);
		current_to_free = next_to_free;
	}
}

t_bool	no_duplicates(t_list *stack)
{
	t_list	*outer;
	t_list	*inner;

	outer = stack;
	while (outer != NULL)
	{
		inner = outer->next;
		while (inner != NULL)
		{
			if (outer->value == inner->value)
				return (false);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (true);
}
