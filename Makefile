NAME			=	push_swap.a
NAME_BONUS		=	push_swapb.a

SRCS			=	push_swap.c ft_split.c do_magic_2.c utils1.c utils2.c moves1.c moves2.c utils3.c push_swap2.c

SRCS_BONUS		=	ft_split.c do_magic_2.c utils1.c utils2.c moves1.c moves2.c utils3.c push_swap2.c \
					push_swap_bonus.c ft_split_bonus.c do_magic_2_bonus.c utils1_bonus.c utils2_bonus.c moves1_bonus.c moves2_bonus.c \
					utils3_bonus.c push_swap2_bonus.c get_next_line.c get_next_line_utils.c bonus_work.c

OBJS			=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

CC				=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus:		$(OBJS_BONUS)
			ar -rcs $(NAME_BONUS) $(OBJS_BONUS)

clean:
			rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -f $(NAME) $(NAME_BONUS)

re:			clean fclean all
