# ******************************** Directories *********************************
INCLUDES_DIR	:= ../include
OBJS_DIR		:= obj

# *********************************** Files ************************************
NAME	:= ../pipex
SRCS	:= 	free.c ft_atoi.c ft_strjoin.c ft_printf_utils_2.c 	get_next_line.c ft_printf.c ft_strncmp.c ft_strcmp.c list.c ft_exit.c 	ft_strlen.c ft_split.c 	\
			get_next_line_utils.c 	ft_printf_utils.c get.c ft_strdup.c pipex_bonus.c here_doc.c open_file.c check.c pipe.c
			
	

OBJS	:= $(SRCS:.c=.o)
HEADERS	:= pipex_bonus.h

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
all : $(NAME)
$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) 
			@$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(OBJS_DIR)/, $(OBJS)) -o $(NAME)
				@make DRAW
				@echo $(CURSIVE)$(BLUE) "					   - Compiling $(NAME) Bonus Part... " $(NONE)
				@echo
				@sleep 0.05
				@echo $(BLUE)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)
				@sleep 0.05
				@echo ""
				@sleep 0.05
				@echo $(CURSIVE)$(RED)"*******************************For Pipex bonus you can use multiple pipes, or use "here_doc"***********************************************"
				@echo $(CURSIVE)$(YELLOW)"To use pipex Bonus multiple pipes Examples:\n	\044>  ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2"
				@echo $(CURSIVE)$(YELLOW)"pipex Bonus support "here_doc" Examples:\n 	\044> ./pipex here_doc LIMITER cmd cmd1 file"
				@echo $(GRY)" file1			: exist file with read permission\n file2     		: will create a new file if does not exist\n cmd1 & cmd2 ... cmdn   : commands Shell\n LIMITER 		: EOF"              

$(OBJS_DIR)/%.o: %.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) 
					@$(MKDIR) $(OBJS_DIR)
					@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

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
