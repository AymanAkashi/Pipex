NAME = pipex

SRCS_DIR = srcs

OBJS_DIR = obj

INCLUDE = include

SRCS = pipex.c ft_split.c ft_atoi.c ft_strlen.c ft_strcmp.c ft_strdup.c ft_strncmp.c ft_strjoin.c ft_exit.c get.c child.c\
		ft_lstnew.c ft_lstadd_back.c list.c free.c

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g


all: $(NAME) $(INCLUDE)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS))
		gcc $(CFLAGS) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o ${NAME}

$(OBJS_DIR)/%.o: ${SRCS_DIR}/%.c
		@mkdir -p obj
		gcc $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
		rm -rf obj
fclean: clean
		rm -rf $(NAME) $(BONUS) $(OBJS_BONUS)
re: fclean all
.PHONY: all clean fclean re
