# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= srcs
BONUS_DIR		:= bonus
OBJS_DIR		:= obj
BONUS_OBJS_DIR	:= obj_bonus

# *********************************** Files ************************************
NAME	:= pipex
NAME_BONUS	:= pipex_bonus
SRCS	:= $(shell ls $(SRCS_DIR))
OBJS	:= $(SRCS:.c=.o)
BONUS	:= $(shell ls $(BONUS_DIR))
BONUS_OBJS	:= $(BONUS:.c=.o)
HEADERS	:= $(shell ls $(INCLUDES_DIR))

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR)
LIBS		:=

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

 tab = "\t"
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS))
		@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) -o $(NAME)
			@make DRAW
			@echo $(CURSIVE)$(BLUE) "					   - Compiling $(NAME) Mandatory... " $(NONE)
			@echo
			@sleep 0.05
			@echo $(BLUE)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)
			@sleep 0.05
			@echo ""
			@sleep 0.05
			@echo $(CURSIVE)$(GRY)"To use pipex Examples:\n	\044> ./pipex infile "cmd1" "cmd2" outfile\n"
			@echo $(GRY)" infile      : exist file with read permission\n outfile     : will create a new file\n cmd1 & cmd2 : commands shell"                        
			@echo ""

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) 
			@$(MKDIR) $(OBJS_DIR)
			@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

bonus : $(NAME_BONUS)
$(NAME_BONUS): $(addprefix $(BONUS_OBJS_DIR)/, $(BONUS_OBJS)) 
			@$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(BONUS_OBJS_DIR)/, $(BONUS_OBJS)) -o $(NAME_BONUS)

$(BONUS_OBJS_DIR)/%.o: $(BONUS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) 
					@$(MKDIR) $(BONUS_OBJS_DIR)
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
	@$(RM) $(OBJS_DIR) $(BONUS_OBJS_DIR)
	@echo $(CURSIVE)$(YELLOW) " 						- Removing object files..." $(NONE)

fclean:	clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo $(CURSIVE)$(YELLOW) " 						- Removing $(NAME)..." $(NONE)

re: fclean all

.PHONY: all clean fclean re
