# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/02/05 18:39:35 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= pipex
# BONUS_NAME		= kari_checker
LIBRARY			= libft.a
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address,integer,undefined
RM				= rm -rf
ECHO			= echo -e

##########################################
# library directory
LIB_DIR			= ./libft
BASE_INC_DIR	= ./libft/inc

# mandatory directory
SRCS_DIR		= ./src
OBJS_DIR		= ./obj
MAN_INC_DIR		= $(BASE_INC_DIR) ./inc

# bonus directory
# BONUS_SRCS_DIR	= ./bonus_src
# BONUS_OBJS_DIR	= ./bonus_obj
# BONUS_INC_DIR	= $(BASE_INC_DIR) ./inc ./bonus_inc

##########################################
# headers files
ORIGIN_HEADERS	= $(wildcard $(BASE_INC_DIR)/*.h)
LIB				= $(LIB_DIR)/$(LIBRARY)

# mandatory files
SRCS 	   		= $(wildcard $(SRCS_DIR)/*.c)
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(ORIGIN_HEADERS) ./inc/pipex.h

# bonus files
# BONUS_SRCS 	   	= $(BONUS_SRCS_DIR)/checker_kari.c
# BONUS_OBJS		= $(subst $(BONUS_SRCS_DIR), $(BONUS_OBJS_DIR), $(BONUS_SRCS:.c=.o))
# BONUS_HEADERS	= $(HEADERS) ./bonus_inc/push_swap_bonus.h

# make obj dir recursively
MAKE_OBJDIR		= $(shell mkdir -p $(subst $(SRCS_DIR), $(OBJS_DIR), $(dir $(SRCS))))
# MAKE_B_OBJDIR	= $(shell mkdir -p $(subst $(BONUS_SRCS_DIR), $(BONUS_OBJS_DIR), $(dir $(BONUS_SRCS))))

# debug info
ifdef DEBUG
CFLAGS += -g -fsanitize=address -fsanitize=integer -DDEBUG
endif

# color and line
DEF_COLOR		=	\033[0;39m
ORANGE			=	\033[0;33m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[1;92m
YELLOW			=	\033[1;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m
LINE			= 	\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500

all:			$(NAME)

bonus:			$(BONUS_NAME)

debug:
				make DEBUG=1 all

$(NAME):		status_check

$(BONUS_NAME):	compile_bonus

status_check:
				cd $(LIB_DIR) && make
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(WHITE)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make compile
				
compile:		$(OBJS) $(HEADERS) $(LIBFT_HEADERS)
				@$(CC) $(CFLAGS) $(foreach dir_list,$(MAN_INC_DIR),-I$(dir_list)) $(OBJS) ./libft/libft.a -o $(NAME)
				@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(GREEN)compiled \u2714$(DEF_COLOR)"

# compile_bonus:	$(BONUS_OBJS) $(BONUS_HEADERS) $(LIBFT_HEADERS)
# 				@$(CC) $(CFLAGS) $(foreach dir_list,$(MAN_INC_DIR),-I$(dir_list)) ./obj/main/copy_argv_to_lst.o  ./obj/main/copy_argv_to_lst_helper.o ./obj/operate/operate_basic_stack_ope1.o  ./obj/operate/operate_basic_stack_ope2.o  ./obj/operate/operate_both_stack.o  ./obj/operate/operate_stack_a.o  ./obj/operate/operate_stack_b.o  ./obj/strategy/ope_long.o  ./obj/strategy/ope_three_four_five_node.o  ./obj/utils/append_sa_if_needed.o  ./obj/utils/push_insert.o  ./obj/utils/struct_modify.o  ./obj/utils/utils_basic.o  ./obj/utils/utils_debug.o  ./obj/utils/utils_list_cmds.o  ./obj/utils/utils_list_query.o  ./obj/utils/utils_struct_get_context.o  ./obj/utils/utils_temp.o  ./obj/utils/utils_trivial.o $(BONUS_OBJS) ./libft/libft.a -o $(BONUS_NAME)

$(OBJS_DIR)/%.o:$(MAKE_OBJDIR) $(SRCS_DIR)/%.c $(HEADERS)
				@$(CC) $(CFLAGS) $(foreach dir_list,$(MAN_INC_DIR),-I$(dir_list)) -c $< -o $@
				@$(ECHO) -n "$(RED)\u2500$(DEF_COLOR)"

# $(BONUS_OBJS_DIR)/%.o:$(MAKE_B_OBJDIR) $(BONUS_SRCS_DIR)/%.c $(BONUS_HEADERS)
# 				@$(CC) $(CFLAGS) $(foreach dir_list,$(BONUS_INC_DIR),-I$(dir_list)) -c $< -o $@

# other cmds
clean:
				@cd $(LIB_DIR) && make clean
				@$(RM) $(OBJS_DIR)
				# @$(RM) $(BONUS_OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			
				@cd $(LIB_DIR) && make fclean
				@$(RM) $(OBJS_DIR)
				# @$(RM) $(BONUS_OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t./$(NAME) \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make

norm:
				@norminette $(SRCS) $(HEADERS); norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)

print_TEST:
				@echo $(BONUS_HEADERS)

make test:
				make
				./test.sh
				

.PHONY:			all clean fclean re bonus norm format_norm debug
