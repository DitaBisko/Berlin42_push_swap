/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:09 by dbisko            #+#    #+#             */
/*   Updated: 2024/07/08 22:01:33 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	fill_stack(char **args, t_list **stack_a, int argument_count)
{
	long	num;
	char	**start;

	start = args;
	num = 0;
	while (*args)
	{
		num = ft_atol(*args);
		if (num < -2147483648 || num > 2147483647)
		{
			write(2, "Error\n", 6);
			free_stack(stack_a);
			free_arr(start, argument_count);
			exit (1);
		}
		if (add_to_stack((int)num, stack_a) == false)
		{
			free_stack(stack_a);
			free_arr(start, argument_count);
			exit (1);
		}
		args++;
	}
}

void	validity_error(char **args, int argument_count)
{
	if (!args_validity_check(args))
	{
		write(2, "Error\n", 6);
		free_arr(args, argument_count);
		exit (1);
	}
}

void	duplicate_error(t_list **stack, char **args, int argument_count)
{
	if (!no_duplicates(*stack))
	{
		free_stack(stack);
		free_arr(args, argument_count);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		argument_count;

	stack_a = NULL;
	stack_b = NULL;
	argument_count = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit (1);
	args = char_num_arr(argv, argc, &argument_count);
	validity_error(args, argument_count);
	fill_stack(args, &stack_a, argument_count);
	duplicate_error(&stack_a, args, argument_count);
	if (!is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_arr(args, argument_count);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit (0);
}
