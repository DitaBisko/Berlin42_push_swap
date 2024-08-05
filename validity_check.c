/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:36:40 by dbisko            #+#    #+#             */
/*   Updated: 2024/02/26 11:36:44 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	one_arg_validation(char *arg)
{
	if (*arg != '-' && *arg != '+' && !(*arg >= '0' && *arg <= '9'))
		return (false);
	arg++;
	while (*arg)
	{
		if (!(*arg >= '0' && *arg <= '9'))
			return (false);
		arg++;
	}
	return (true);
}

t_bool	args_validity_check(char **args)
{
	while (*args)
	{
		if (one_arg_validation(*args) == false)
			return (false);
		args++;
	}
	return (true);
}
/*
t_bool	no_duplicates(t_list **stack)
{
	t_list	**outer;
	t_list	**inner;

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
}*/
