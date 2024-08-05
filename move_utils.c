/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:39:51 by dbisko            #+#    #+#             */
/*   Updated: 2024/03/05 12:45:06 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move(char *move, char stack_indicator)
{
	while (*move != '\0')
	{
		write(1, move, 1);
		move++;
	}
	write(1, &stack_indicator, 1);
	write(1, "\n", 1);
}

void	perform_rot(t_list **stack, int rot, char s)
{
	int	move_count;

	move_count = 0;
	while (move_count < rot)
	{
		rotate(stack);
		print_move("r", s);
		move_count++;
	}
}

void	perform_rev_rot(t_list **stack, int rot, char s)
{
	int	move_count;

	move_count = 0;
	while (move_count < rot)
	{
		reverse_rotate(stack);
		print_move("rr", s);
		move_count++;
	}
}

void	perform_swap(t_list **stack, char s)
{
	swap_first_two(stack);
	write(1, "s", 1);
	write(1, &s, 1);
	write(1, "\n", 1);
}
