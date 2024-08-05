CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap

SRCS = algo_utils.c\
		arr_utils.c\
  		find_utils.c\
  		ft_split.c\
  		join_argv.c\
  		move.c\
  		move_price.c\
  		move_price_utils.c\
  		move_utils.c\
  		push_swap_main.c\
  		rotate_till_sorted.c\
  		set_attributes.c\
  		set_attributes_utils.c\
  		sort_check.c sort_small.c\
  		stack_utils.c\
  		validity_check.c\
  		push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)
	$(MAKE) clean

.PHONY: all clean fclean re

