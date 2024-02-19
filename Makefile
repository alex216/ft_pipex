# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/02/19 16:39:42 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= pipex
LIBRARY			= libft.a
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address,integer,undefined
RM				= rm -rf
ECHO			= echo -e

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
LINE			= 	\u2500\u2500


##########################################
# library directory
LIB_DIR			= ./libft
BASE_INC_DIR	= ./libft/inc

# mandatory directory
SRCS_DIR		= ./src
OBJS_DIR		= ./obj
MAN_INC_DIR		= $(BASE_INC_DIR) ./inc

##########################################
# base files
LIB				= $(LIB_DIR)/$(LIBRARY)

ORIGIN_HEADERS	= ./inc/$(NAME).h \
				  ./inc/utils.h \
				  ./inc/process.h

BASIC_SRCS 		= ./src/process/process.c \
				  ./src/utils/utils.c \

# mandatory files
SRCS			= $(BASIC_SRCS) ./src/main.c
BASIC_OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(BASIC_SRCS:.c=.o))
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(ORIGIN_HEADERS)

##########################################

all:			$(NAME)

$(NAME):		$(LIB) $(SRCS)
				@make man_step_0

$(LIB):
				@make -C ./libft

man_step_0:			
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(WHITE)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make man_step_1

man_step_1:		$(OBJS) $(LIB)
				@$(CC) $(CFLAGS) $^ -o $(NAME)
				@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(GREEN)compiled \u2714$(DEF_COLOR)"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c $(HEADERS)
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(foreach dir_list,$(MAN_INC_DIR),-I$(dir_list)) -c $< -o $@
				@$(ECHO) -n "$(RED)\u2500$(DEF_COLOR)"

# other cmds
clean:
				@make fclean -C $(LIB_DIR)
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			
				@make clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(NAME)]\t\t./$(NAME) \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make

norm:
				@norminette $(SRCS) $(HEADERS) | grep -v 'OK'; norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)
				@make norm

test:
				@make all
				@test.sh

.PHONY:			all clean fclean re bonus norm format_norm test
