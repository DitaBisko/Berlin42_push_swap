/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:48:24 by dbisko            #+#    #+#             */
/*   Updated: 2024/04/23 11:36:36 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_node(t_list *node, t_list **from, t_list **to, char node_stk_idk)
{
	if (node->move_to_make == 1)
		both_above_med(from, to, node, node_stk_idk);
	else if (node->move_to_make == 2)
		both_below_med(from, to, node, node_stk_idk);
	else if (node->move_to_make == 3)
		node_above_med(from, to, node, node_stk_idk);
	else
		node_below_med(from, to, node, node_stk_idk);
}

void	both_above_med(t_list **from, t_list **to,
			t_list *node, char node_stk_idk)
{
	char	target_stk;
	int		node_rot;
	int		target_rot;

	if (node_stk_idk == 'a')
		target_stk = 'b';
	else
		target_stk = 'a';
	node_rot = node->index;
	target_rot = node->target->index;
	while (node_rot > 0 && target_rot > 0)
	{
		rotate(from);
		rotate(to);
		write(1, "rr\n", 3);
		node_rot--;
		target_rot--;
	}
	if (node_rot > target_rot)
		perform_rot(from, node_rot, node_stk_idk);
	else if (target_rot > node_rot)
		perform_rot(to, target_rot, target_stk);
	push_to_stack(from, to);
	print_move("p", target_stk);
}

void	both_below_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind)
{
	char	target_stk_ind;
	int		rot_node;
	int		rot_target;

	if (node_stk_ind == 'a')
		target_stk_ind = 'b';
	else
		target_stk_ind = 'a';
	rot_node = node->stk_len - node->index;
	rot_target = node->target->stk_len - node->target->index;
	while (rot_node > 0 && rot_target > 0)
	{
		reverse_rotate(from);
		reverse_rotate(to);
		write(1, "rrr\n", 4);
		rot_node--;
		rot_target--;
	}
	if (rot_node > rot_target)
		perform_rev_rot(from, rot_node, node_stk_ind);
	else if (rot_target > rot_node)
		perform_rev_rot(to, rot_target, target_stk_ind);
	push_to_stack(from, to);
	print_move("p", target_stk_ind);
}

void	node_above_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind)
{
	char	target_stk_ind;
	int		rot_count;

	if (node_stk_ind == 'a')
		target_stk_ind = 'b';
	else
		target_stk_ind = 'a';
	rot_count = node->index;
	perform_rot(from, rot_count, node_stk_ind);
	rot_count = (node->target->stk_len - node->target->index);
	perform_rev_rot(to, rot_count, target_stk_ind);
	push_to_stack(from, to);
	print_move("p", target_stk_ind);
}

void	node_below_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind)
{
	char	target_stk_ind;
	int		rot_count;

	if (node_stk_ind == 'a')
		target_stk_ind = 'b';
	else
		target_stk_ind = 'a';
	if ((node->stk_len - node->index) == 0)
		rot_count = 1;
	else
		rot_count = node->stk_len - node->index;
	perform_rev_rot(from, rot_count, node_stk_ind);
	rot_count = node->target->index;
	perform_rot(to, rot_count, target_stk_ind);
	push_to_stack(from, to);
	print_move("p", target_stk_ind);
}
