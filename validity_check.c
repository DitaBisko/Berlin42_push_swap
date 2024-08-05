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

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

t_bool	args_validity_check(char **args)
{
	while (*args)
	{
		if (*args[0] == '\0' && ft_strlen(*args) == 0)
			return (false);
		if (*args[0] == '-' && ft_strlen(*args) == 1)
			return (false);
		if (*args[0] == '+' && ft_strlen(*args) == 1)
			return (false);
		if (one_arg_validation(*args) == false)
			return (false);
		args++;
	}
	return (true);
}
