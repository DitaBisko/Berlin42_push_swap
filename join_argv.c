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

int	word_len_one_space(char *str)
{
	int	len;
	int	space_flag;

	len = 0;
	space_flag = 0;
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
		{
			if (space_flag == 0)
			{
				len++;
				space_flag = 1;
			}
		}
		else
		{
			len++;
			space_flag = 0;
		}
		str++;
	}
	return (len);
}

int	len_total_args(char **args, int count)
{
	int	args_i;
	int	len;

	len = 0;
	args_i = 1;
	while (args_i < count)
	{
		len += word_len_one_space(args[args_i]);
		if (args_i < count - 1)
			len++;
		args_i++;
	}
	return (len);
}

void	assign_word(char *dst, char *src)
{
	int	in_word;

	in_word = 0;
	while (*src)
	{
		if (*src == ' ' || (*src >= 9 && *src <= 13))
		{
			if (in_word == 1)
			{
				*dst++ = ' ';
				in_word = 0;
			}
			while (*src == ' ' || (*src >= 9 && *src <= 13))
				src++;
		}
		else
		{
			*dst++ = *src++;
			in_word = 1;
		}
	}
	*dst = '\0';
}

char	*concat_args(char **args, int count)
{
	char	*str;
	char	*start;
	int		len;
	int		index;

	str = NULL;
	len = len_total_args(args, count);
	str = malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	start = str;
	index = 1;
	while (index < count)
	{
		assign_word(str, args[index]);
		while (*str)
			str++;
		if (index < count - 1)
			*str++ = ' ';
		index++;
	}
	*str = '\0';
	return (start);
}
