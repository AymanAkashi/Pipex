# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= srcs
OBJS_DIR		:= obj
LIBS_DIR		:=

# *********************************** Files ************************************
NAME	:= pipex
MAIN	:=
SRCS	:= $(shell ls $(SRCS_DIR))
OBJS	:= $(SRCS:.c=.o)
HEADERS	:= $(shell ls $(INCLUDES_DIR))

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
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

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS))
		@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) \
		$(MAIN) -o $(NAME)
			@echo $(CURSIVE)$(GREEN)"					 ██▓███   ██▓ ██▓███  ▓█████ ▒██   ██▒ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					▓██░  ██▒▓██▒▓██░  ██▒▓█   ▀ ▒▒ █ █ ▒░ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					▓██░ ██▓▒▒██▒▓██░ ██▓▒▒███   ░░  █   ░ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					▒██▄█▓▒ ▒░██░▒██▄█▓▒ ▒▒▓█  ▄  ░ █ █ ▒  "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					▒██▒ ░  ░░██░▒██▒ ░  ░░▒████▒▒██▒ ▒██▒ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					▒▓▒░ ░  ░░▓  ▒▓▒░ ░  ░░░ ▒░ ░▒▒ ░ ░▓ ░ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					░▒ ░      ▒ ░░▒ ░      ░ ░  ░░░   ░▒ ░ "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					░░        ▒ ░░░          ░    ░    ░   "$(NONE)
			@echo $(CURSIVE)$(GREEN)"					          ░              ░  ░ ░    ░   "$(NONE)
			@echo $(CURSIVE)$(BLUE) "					    - Compiling $(NAME) Mandatory... " $(NONE)
			@echo $(GRY)"	                 - ------------------------------🅓 🅞 🅝 🅔----------------------------- -"$(NONE)                          

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) 
	@$(MKDIR) $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@$(RM) $(OBJS_DIR)
	@echo $(CURSIVE)$(YELLOW) " 						- Removing object files..." $(NONE)

fclean:	clean
	@$(RM) $(NAME)
	@echo $(CURSIVE)$(YELLOW) " 						- Removing $(NAME)..." $(NONE)

re: fclean all

.PHONY: all clean fclean re
