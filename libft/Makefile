# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 18:12:04 by yliu              #+#    #+#              #
#    Updated: 2024/01/31 18:37:43 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

#compiler option and etc
NAME			= libft.a
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
ECHO			= echo -e

#directory
SRCS_DIR		= ./src/
OBJS_DIR		= ./obj/
INCLUDE			= ./inc/

#files
SRCS 			= $(wildcard $(SRCS_DIR)ft_*/*.c)
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 		= $(wildcard $(INCLUDE)/*.h)

#make obj dir recursively
MAKE_OBJDIR		= $(shell mkdir -p $(subst $(SRCS_DIR), $(OBJS_DIR), $(dir $(SRCS))))

#color and line
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
LINE			=   \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500

all:			$(NAME)

$(NAME):		status_check

status_check:
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\t\tlibft.a \t$(WHITE)checking...$(DEF_COLOR)"
				@$(ECHO) -n "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
				@make compile

compile:		$(OBJS)
				@$(AR) crs $(NAME) $?
				@$(ECHO) -n "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
				@$(ECHO) "$(GREEN) \u2023 100% $(DEF_COLOR)"
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\t\tlibft.a \t$(GREEN)compiled \u2714$(DEF_COLOR)"

$(OBJS_DIR)%.o:	$(MAKE_OBJDIR) $(DROW_GRA) $(SRCS_DIR)%.c $(HEADERS)

				@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
				@$(ECHO) -n "$(RED)\u2500$(DEF_COLOR)"

#other cmds

clean:
				@$(RM) $(OBJS_DIR)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\t\tobject files \t$(GREEN)deleted \u2714$(DEF_COLOR)"

fclean:			clean
				@$(RM) $(NAME)
				@$(ECHO) "$(DEF_COLOR)$(BLUE)[LIBFT]\t\tlibft.a \t$(GREEN)deleted \u2714$(DEF_COLOR)"

re:				fclean
				@make

norm:
				@norminette $(SRCS) $(HEADERS); norminette -v

format_norm:
				@c_formatter_42 $(SRCS) $(HEADERS)

debug:			$(CFLAGS) += -g -fsanitize=address -fsanitize=leaks\
				fsanitize=integer

.PHONY:			all clean fclean re bonus norm format_norm debug
