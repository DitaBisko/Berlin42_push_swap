/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:28:12 by dbisko            #+#    #+#             */
/*   Updated: 2024/07/06 11:28:17 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_2_to_b(t_list **stack_a, t_list **stack_b)
{
	if (stack_size(stack_a) == 4)
	{
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
	}
	else
	{
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_to_move;
	int		i;

	i = stack_size(stack_a);
	while (i > 3)
	{
		node_to_move = find_cheapest(stack_a);
		move_a_node(node_to_move, stack_a, stack_b, 'a');
		set_attributes_a(stack_a, stack_b);
		i--;
	}
}

void	push_to_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*node_to_move;
	int		i;

	i = stack_size(stack_b);
	while (i > 0)
	{
		node_to_move = find_cheapest(stack_b);
		move_a_node(node_to_move, stack_b, stack_a, 'b');
		set_attributes_b(stack_b, stack_a);
		i--;
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	if (stack_size(stack_a) == 1)
		return ;
	if (stack_size(stack_a) == 2)
	{
		if (!is_sorted(stack_a))
			perform_swap(stack_a, 'a');
		return ;
	}
	if (stack_size(stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	push_first_2_to_b(stack_a, stack_b);
	set_attributes_a(stack_a, stack_b);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	set_attributes_b(stack_b, stack_a);
	push_to_a(stack_b, stack_a);
	rotate_till_sorted(stack_a);
}

/*
void push_swap(t_list **stack_a, t_list **stack_b)
{
	t_list *node_to_move;
	int	push_to_target_stack;

	if (stack_size(stack_a) == 1)
		return;
	if (stack_size(stack_a) == 2)
	{
		if(!is_sorted(stack_a))
			perform_swap(stack_a, 'a');
		return;
	}
	//if stack size <= 3 -> sort three
	if (stack_size(stack_a) == 3)
	{
		sort_three(stack_a);
		return;
	}

	// push 2 to stack b
	if (stack_size(stack_a) == 4)
	{
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
	}
	else
	{
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
		push_to_stack(stack_a, stack_b);
		print_move("p", 'b');
	}

	// set attributes to stack a
	set_attributes_a(stack_a, stack_b);

	// push all but 3 in descending order to stack b
	push_to_target_stack = stack_size(stack_a);

	while (push_to_target_stack > 3)
	{
		node_to_move = find_cheapest(stack_a);
		move_a_node(node_to_move, stack_a, stack_b, 'a');
		set_attributes_a(stack_a, stack_b);
		push_to_target_stack--;
	}


	sort_three(stack_a);

	set_attributes_b(stack_b, stack_a);

	push_to_target_stack = stack_size(stack_b);

	while (push_to_target_stack != 0)
	{
		node_to_move = find_cheapest(stack_b);
		move_a_node(node_to_move, stack_b, stack_a, 'b');
		set_attributes_b(stack_b, stack_a);
		push_to_target_stack--;
	}
	rotate_till_sorted(stack_a);
}
*/