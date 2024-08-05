/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:28:02 by dbisko            #+#    #+#             */
/*   Updated: 2024/07/04 13:19:21 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef enum Bool
{
	false,
	true
}	t_bool;

typedef struct s_list
{
	int				stk_len;
	int				index;
	int				value;
	int				cost;
	int				move_to_make;
	t_bool			above_median;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

char	*concat_args(char **args, int count);
char	**ft_split(char *str, char sep);

void	assign_word(char *dst, char *src);
void	free_arr(char **arr, int count);
void	free_stack(t_list **stack);

int		word_len_one_space(char *str);
int		len_total_args(char **args, int count);
int		count_words(char *str, char sep);
int		word_len(char *str, char sep);
int		place_words(char **arr, char *str, char sep, int wc);

long	ft_atol(const char *str);

t_bool	args_validity_check(char **args);
t_bool	add_to_stack(int num, t_list **stack);
t_bool	no_duplicates(t_list *stack);
t_bool	is_sorted(t_list **stack);

// set attributes
void	set_attributes_a(t_list **stack_a, t_list **stack_b);
void	set_attributes_b(t_list **stack_b, t_list **stack_a);

// move price
void	move_price(t_list *node);

// move price utils

t_bool	min_cost(int compare_to, int compare_1, int compare_2, int compare_3);
void	place_price(t_list *node, int move, int price);

// set attributes utils
int		stack_size(t_list **stack);
void	set_target_a(t_list **stack_a, t_list **stack_b);
void	set_target_b(t_list **stack_b, t_list **stack_a);
void	set_current_pos(t_list **stack);
void	set_stk_size(t_list **stack);
void	set_above_med(t_list **stack);

// move
void	move_a_node(t_list *node, t_list **from,
			t_list **to, char node_stk_idk);
void	both_above_med(t_list **from, t_list **to,
			t_list *node, char node_stk_idk);
void	both_below_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind);
void	node_above_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind);
void	node_below_med(t_list **from, t_list **to,
			t_list *node, char node_stk_ind);

//move utils
void	print_move(char *move, char stack_indicator);
void	perform_rot(t_list **stack, int rot, char s);
void	perform_rev_rot(t_list **stack, int rot, char s);
void	perform_swap(t_list **stack, char s);

// rotate till sorted
void	rotate_till_sorted(t_list **stack);

// sort three
void	sort_three(t_list **stack);

// algo utils
void	push_to_stack(t_list **from, t_list **to);
void	swap_first_two(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

// find utils
t_list	*find_min(t_list **stack);
t_list	*find_max(t_list **stack);
t_list	*find_cheapest(t_list **stack);

// arr utils
char	**char_num_arr(char **argv, int argc, int *word_count);

// push swap
void	push_swap(t_list **stack_a, t_list **stack_b);

#endif