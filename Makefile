# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/04/22 18:29:13 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler option and etc
NAME			:= pipex
LIBRARY			:= libft.a
WARNING			:= -Wall -Wextra -Werror
RM				:= rm -rf
ECHO			:= printf
MMD_MP			:= -MMD -MP
ifeq ($(shell uname),Linux)
SANITIZE		:= -g -fsanitize=address,undefined
else ifeq ($(shell uname),Debian)
SANITIZE		:= -g -fsanitize=address,integer,undefined
endif

# color and line
DEF_COLOR		:=	\033[0;39m
ORANGE			:=	\033[0;33m
GRAY			:=	\033[0;90m
RED				:=	\033[0;91m
GREEN			:=	\033[1;92m
YELLOW			:=	\033[1;93m
BLUE			:=	\033[0;94m
MAGENTA			:=	\033[0;95m
CYAN			:=	\033[0;96m
WHITE			:=	\033[0;97m
-				:=	━
FILE_NUM		= $(words $(SRCS))
LINE			= $(shell yes $- | head -n $(FILE_NUM) | tr -d '\n'; echo)


##########################################
# library directory
LIB_DIR			:= ./libft
LIB_INC_DIR	:= ./libft/inc

# mandatory directory
SRCS_DIR		:= ./src
OBJS_DIR		:= ./obj
INC_DIR			:= ./inc
MAN_INC_DIR		:= $(LIB_INC_DIR) $(INC_DIR)

##########################################
# base files
LIB				:= $(LIB_DIR)/$(LIBRARY)

ORIGIN_HEADERS	:=	./inc/$(NAME).h \
					./inc/utils.h \
					./inc/process.h \
					./inc/parse_string.h

BASIC_SRCS 		:=	./src/process/process.c \
				  	./src/process/return_infile_fd.c \
				  	./src/process/return_outfile_fd.c \
				  	./src/process/exec_process/exec_process.c \
				  	./src/utils/utils.c \
					./src/utils/utils_struct.c \
					./src/utils/operate_record.c \
					./src/utils/error.c \
					./src/utils_xwrapper/xaccess_is.c \
				  	./src/utils_xwrapper/xclose.c \
				  	./src/utils_xwrapper/xdup2.c \
					./src/process/exec_process/return_entire_path.c \
					./src/process/exec_process/parse_string/parse_string.c

# mandatory files
SRCS			:= $(BASIC_SRCS) ./src/main.c
BASIC_OBJS		:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(BASIC_SRCS:.c=.o))
OBJS			:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
DEP				:= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.d))
HEADERS 	   	:= $(ORIGIN_HEADERS)

##########################################

.PHONY:			all
all:			$(NAME)

$(NAME):		$(LIB) $(SRCS)
				@make -s man_step_0

$(LIB):
				@git submodule update --init --recursive
				@make -s -C ./libft

.PHONY:			man_step_0
man_step_0:
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(WHITE)checking...$(DEF_COLOR)\n"
				@$(ECHO) "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make -s man_step_1

.PHONY:			man_step_1
man_step_1:		$(OBJS) $(LIB)
				@$(CC) $(CFLAGS) $^ -o $(NAME)
				@$(ECHO) "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) ‣ 100%% $(DEF_COLOR)\n"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(GREEN)compiled ✓$(DEF_COLOR)\n"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c $(HEADERS)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(MMD_MP) $(foreach dir_element,$(MAN_INC_DIR),-I$(dir_element)) -c $< -o $@
				@$(ECHO) "$(RED)$-$(DEF_COLOR)"

-include $(DEP)
##########################################
# other cmds
.PHONY:			clean
clean:			test_clean
				@make -s fclean -C $(LIB_DIR) || true
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\tobject files \t$(GREEN)deleted ✓$(DEF_COLOR)\n"

.PHONY:			fclean
fclean:			clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(GREEN)deleted ✓$(DEF_COLOR)\n"

.PHONY:			re
re:				fclean all

.PHONY:			norm
norm:
				@norminette $(SRCS) $(HEADERS) | grep -v 'OK'; norminette -v

.PHONY:			format_norm
format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)
				@make -s norm

.PHONY:			xtest
xtest:
				@make -s all
				@xtest.sh

include Makefile_tester.mk
