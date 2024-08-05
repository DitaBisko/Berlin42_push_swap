/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_till_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:34:54 by dbisko            #+#    #+#             */
/*   Updated: 2024/03/05 17:00:35 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_till_sorted(t_list **stack)
{
	t_list	*min;
	int		rot_count;

	min = find_min(stack);
	if (min->above_median == true)
	{
		rot_count = min->index;
		perform_rot(stack, rot_count, 'a');
	}
	else
	{
		rot_count = min->stk_len - min->index;
		perform_rev_rot(stack, rot_count, 'a');
	}
}
