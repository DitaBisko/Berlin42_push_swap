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

char	**char_num_arr(char **argv, int argc, int *word_count)
{
	char	*args;
	char	**sep_args;

	args = concat_args(argv, argc);
	*word_count = count_words(args, ' ');
	sep_args = ft_split(args, ' ');
	free(args);
	return (sep_args);
}
