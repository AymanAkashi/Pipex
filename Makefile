# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= srcs
BONUS_DIR		:= bonus
OBJS_DIR		:= obj
BONUS_OBJS_DIR	:= obj_bonus

# *********************************** Files ************************************
NAME	:= pipex
NAME_BONUS	:= pipex
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
all: ET_SRCS


bonus : ET_BONUS

ET_SRCS :
			@cd $(SRCS_DIR) && make

clean:
	@cd $(BONUS_DIR) && make clean
	@cd $(SRCS_DIR) && make clean
	@echo $(CURSIVE)$(YELLOW) " 						- Removing object files..." $(NONE)

ET_BONUS : 
			@cd $(BONUS_DIR) && make


fclean:	clean
	@cd $(BONUS_DIR) && make clean
	@cd $(SRCS_DIR) && make clean
	@rm -rf $(NAME)
	@echo $(CURSIVE)$(YELLOW) " 						- Removing $(NAME)..." $(NONE)

re: fclean all

.PHONY: all clean fclean re
