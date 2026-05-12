CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
BUFFER_SIZE	=	4096
DFLAGS		=	-D BUFFER_SIZE=$(BUFFER_SIZE)

NAME		=	get_next_line.a
SRCS		=	get_next_line.c get_next_line_utils.c
OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created successfully"

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "All files cleaned"

re: fclean all

.PHONY: all clean fclean re
