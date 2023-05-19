NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
AR				= ar crs

SRCS			= $(shell find . -name "*.c")

OBJS			= $(SRCS:.c=.o)

all:	$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
			$(AR) $@ $^

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re