# ******************************** Directories *********************************
INCLUDES_DIR	:= ../include
OBJS_DIR		:=obj


# *********************************** Files ************************************
NAME	:= ../pipex
SRCS	:= child.c free.c ft_atoi.c ft_exit.c ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_split.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c get.c list.c pipex.c
OBJS	:= $(SRCS:.c=.o)
HEADERS	:= pipex.h




# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR) 

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ***********************************Color**************************************

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRY='\033[2;37m'
CURSIVE='\033[3m'
RED ='\033[0;31m'
BLUE = '\033[0;34m'
RESET = \033[0m
CHANGE = \033[0;35m



# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
			@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) -o $(NAME)
			@make DRAW
			@echo $(CURSIVE)$(BLUE) "					   - Compiling pipex Mandatory... " $(NONE)
			@echo
			@sleep 0.05
			@echo $(BLUE)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)
			@sleep 0.05
			@echo ""
			@sleep 0.05
			@echo $(CURSIVE)$(GRY)"To use pipex Examples:\n	\044> ./pipex infile "cmd1" "cmd2" outfile\n"
			@echo $(GRY)" infile      : exist file with read permission\n outfile     : will create a new file\n cmd1 & cmd2 : commands shell"                        
			@echo ""

$(OBJS_DIR)/%.o: %.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) 
			@$(MKDIR) $(OBJS_DIR)
			@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
	$(LIBFT_DIR)/$(INCLUDES_DIR)/$(LIBFT_HEADER)
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

DRAW : 		
			@echo
			@echo $(CURSIVE)$(RED)"					 ██▓███   ██▓ ██▓███  ▓█████ ▒██   ██▒ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					▓██░  ██▒▓██▒▓██░  ██▒▓█   ▀ ▒▒ █ █ ▒░ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					▓██░ ██▓▒▒██▒▓██░ ██▓▒▒███   ░░  █   ░ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					▒██▄█▓▒ ▒░██░▒██▄█▓▒ ▒▒▓█  ▄  ░ █ █ ▒  "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					▒██▒ ░  ░░██░▒██▒ ░  ░░▒████▒▒██▒ ▒██▒ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					▒▓▒░ ░  ░░▓  ▒▓▒░ ░  ░░░ ▒░ ░▒▒ ░ ░▓ ░ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					░▒ ░      ▒ ░░▒ ░      ░ ░  ░░░   ░▒ ░ "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					░░        ▒ ░░░          ░    ░    ░   "$(NONE)
			@sleep 0.05
			@echo $(CURSIVE)$(RED)"					          ░              ░  ░ ░    ░   "$(NONE)
			@sleep 0.05
			@echo

clean:
	@$(RM) $(OBJS_DIR)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
