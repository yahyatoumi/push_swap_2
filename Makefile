NAME	=	push_swap.a

SRCS	=	push_swap.c ft_split.c do_magic_2.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)
fclean:		clean
			rm -f $(NAME)