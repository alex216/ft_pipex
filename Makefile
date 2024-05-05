# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/05/05 11:22:08 by yliu             ###   ########.fr        #
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
CFLAGS			:= $(WARNING) $(SANITIZE)

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
BAR_LEN			= 42
LINE			= $(shell yes $- | head -n $(BAR_LEN) | tr -d '\n'; echo)

FILE_NUM		= $(words $(SRCS))
DIFF_LINE		= $(shell yes $- | head -n $(DIFF) | tr -d '\n'; echo)

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
					./inc/main_helper.h \
					./inc/utils.h \
					./inc/dlist.h \
					./inc/xwrapper.h \
					./inc/xfork_exec.h \
					./inc/here_doc.h \
					./inc/parse_string.h

BASIC_SRCS 		:=	./src/main/init_info.c \
					./src/main/main_helper/pipe_utils.c \
					./src/main/loop_xfork.c \
					\
					./src/here_doc/here_doc.c \
					\
					./src/xfork_exec/xfork_exec.c \
				  	./src/xfork_exec/overtake_io_fd.c \
				  	./src/xfork_exec/exec_process/exec_process.c \
					\
				  	./src/utils/utils.c \
				  	./src/utils/argv_check_utils.c \
					./src/utils/error.c \
					\
					./src/utils/dlist/query_dlist.c \
					./src/utils/dlist/command_dlist.c \
					\
					./src/utils/xwrapper/xaccess_is.c \
				  	./src/utils/xwrapper/xclose.c \
				  	./src/utils/xwrapper/xdup2.c \
				  	./src/utils/xwrapper/xfork.c \
				  	./src/utils/xwrapper/xpipe.c \
					\
					./src/xfork_exec/exec_process/return_entire_path.c \
					./src/xfork_exec/exec_process/parse_string/concat_token.c \
					./src/xfork_exec/exec_process/parse_string/parse_string.c \
					./src/xfork_exec/exec_process/parse_string/remove_quote.c \
					./src/xfork_exec/exec_process/parse_string/parse_string_by_blank.c \
					./src/xfork_exec/exec_process/parse_string/parse_string_extract.c \
					./src/xfork_exec/exec_process/parse_string/parse_string_helper.c

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

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(MMD_MP) $(foreach dir_element,$(MAN_INC_DIR),-I$(dir_element)) -c $< -o $@
				make -s output_diff

ITER			= 0
DIFF			= 0
PREV			= 0
.PHONY:			output_diff
output_diff:
				$(eval ITER=$(shell echo $$(($(ITER) + 1))))
				$(eval NEW=$(shell echo $$(($(ITER) * $(BAR_LEN) / $(FILE_NUM)))))
				$(eval DIFF=$(shell echo $$(($(NEW) - $(PREV)))))
				$(eval PREV=$(shell echo $$(($(NEW)))))
				@$(ECHO) "$(RED)$(DIFF_LINE)$(DEF_COLOR)"

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
