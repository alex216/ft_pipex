# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 12:04:47 by yliu              #+#    #+#              #
#    Updated: 2024/02/20 17:35:25 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/zsh

# compiler option and etc
NAME			= pipex
LIBRARY			= libft.a
CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=address,integer,undefined
CXXFLAGS		= -std=c++17 -Wall -Wextra -Werror
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
				  ./src/process/close_fd.c \
				  ./src/process/replace_fd.c \
				  ./src/process/exec_process.c \
				  ./src/process/return_infile_fd.c \
				  ./src/process/return_outfile_fd.c

# mandatory files
SRCS			= $(BASIC_SRCS) ./src/main.c
BASIC_OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(BASIC_SRCS:.c=.o))
OBJS			= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))
HEADERS 	   	= $(ORIGIN_HEADERS)

##########################################
# test

TEST_NAME		= tester

# directory
TEST_SRCS_DIR	= ./test/unit
GTEST_SRCS_DIR	= ./test/unit/gtest
TEST_OBJS_DIR	= ./test/obj

# src files
TEST_SRCS		= $(TEST_SRCS_DIR)/test_check_args.cpp \
GTEST_SRCS		= $(GTEST_SRCS_DIR)/gtest_main.cc \
				  $(GTEST_SRCS_DIR)/gtest-all.cc

# obj files
TEST_OBJS		= $(subst $(TEST_SRCS_DIR), $(TEST_OBJS_DIR), $(TEST_SRCS:.cpp=.o))
# GTEST_OBJS		= $(subst $(GTEST_SRCS_DIR), $(TEST_OBJS_DIR), $(GTEST_SRCS:.cc=.o))
GTEST_OBJ		= $(patsubst $(GTEST_SRCS_DIR)/%.cc, $(TEST_OBJS_DIR)/%.o, $(GTEST_SRCS))
OBJ_FILTER_MAIN	= $(filter-out $(OBJS_DIR)/main.o, $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)))

# gtest settings
GTEST_VERSION	= 1.14.0
GTEST_ARCHIVE	= v$(GTEST_VERSION).tar.gz
GTEST_REPO_URL	= https://github.com/google/googletest/archive/refs/tags/$(GTEST_ARCHIVE)
GTEST_SRC_DIR	= googletest-$(GTEST_VERSION)
GTEST_FUSE_URL	= https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/$(GTEST_FUSE)
GTEST_FUSE		= fuse_gtest_files.py
##########################################
all:			$(NAME)

$(NAME):		$(LIB) $(SRCS)
				@git submodule update --init --recursive 
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

# test:
# 				@make all
# 				@xtest.sh
# =======
# test:
# 				@make all
# 				@test.sh

##########################################
test:			all $(GTEST_OBJS) $(TEST_OBJS)
	echo "$(BLUE)\ntest linking$(RESET)"
	# @$(CXX) -L $(LIB_DIR) -lft -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJS) $(GTEST_OBJS) -o $(TEST_NAME)
	$(CXX) -L $(LIB_DIR) -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJS) $(GTEST_OBJS) -o $(TEST_NAME)
	./$(TEST_NAME)
	$(RM) $(TEST_NAME)

test_clean:
	@echo "$(BLUE)test cleaning$(RESET)"
	$(RM) -r $(TEST_OBJS_DIR)

retest: test_clean test

$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.cpp $(HEADERS) ./inc/utils.h ./inc/pipex.h
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I ./libft/inc -I ./inc -c $< -o $@
	printf "$(GREEN).$(RESET)"

$(GTEST_OBJS): $(GTEST_SRCS_DIR)
	echo "$(BLUE)test compiling$(RESET)"
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) ./inc -c $(GTEST_SRCS_DIR)/gtest-all.cc -o $(TEST_OBJS_DIR)/gtest-all.o
	printf "$(GREEN).$(RESET)"
	$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) ./inc -c $(GTEST_SRCS_DIR)/gtest_main.cc -o $(TEST_OBJS_DIR)/gtest_main.o
	printf "$(GREEN).$(RESET)"

$(GTEST_SRCS_DIR):
	echo "fetching google test"
	curl -#OL $(GTEST_REPO_URL)
	echo "fetching fuse_gtest_files.py"
	curl -#OL $(GTEST_FUSE_URL)
	tar -xzf $(GTEST_ARCHIVE) $(GTEST_SRC_DIR)
	python3 $(GTEST_FUSE) $(GTEST_SRC_DIR)/googletest $(GTEST_SRCS_DIR)
	mv $(GTEST_SRC_DIR)/googletest/src/gtest_main.cc $(GTEST_SRCS_DIR)
	mv $(GTEST_SRCS_DIR)/gtest/* $(GTEST_SRCS_DIR)
	$(RM) -r $(GTEST_SRC_DIR) $(GTEST_SRCS_DIR)/gtest $(GTEST_ARCHIVE) $(GTEST_FUSE)

.PHONY:			all clean fclean re bonus norm format_norm test
