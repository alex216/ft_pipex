# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_tester.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:53:08 by yliu              #+#    #+#              #
#    Updated: 2024/02/22 20:07:31 by yliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# test
TEST_NAME		:= tester
CXXFLAGS		:= -std=c++17 $(WARNING) -DGTEST=1

# gtest option
GTEST_VERSION	:= 1.14.0
GTEST_ARCHIVE	:= v$(GTEST_VERSION).tar.gz
GTEST_REPO_URL	:= https://github.com/google/googletest/archive/refs/tags/$(GTEST_ARCHIVE)
GTEST_SRC_DIR	:= googletest-$(GTEST_VERSION)
GTEST_FUSE_URL	:= https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/$(GTEST_FUSE)
GTEST_FUSE		:= fuse_gtest_files.py

##########################################
# directory
TEST_SRCS_DIR	:= ./test/unit
GTEST_SRCS_DIR	:= ./test/unit/gtest
TEST_OBJS_DIR	:= ./test/obj

##########################################
# src files
GTEST_SRCS		:= $(GTEST_SRCS_DIR)/gtest_main.cc \
				  $(GTEST_SRCS_DIR)/gtest-all.cc

TEST_SRCS		:= $(TEST_SRCS_DIR)/test_check_args.cpp

# obj files
TEST_OBJS		:= $(subst $(TEST_SRCS_DIR), $(TEST_OBJS_DIR), $(TEST_SRCS:.cpp=.o))
GTEST_OBJS		= $(subst $(GTEST_SRCS_DIR), $(TEST_OBJS_DIR), $(GTEST_SRCS:.cc=.o))
OBJ_FILTER_MAIN	:= $(filter-out $(OBJS_DIR)/main.o, $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)))

ifdef DEBUG
    export DEBUG_FLAG := DEBUG1=1
endif

##########################################
.PHONY:		test
test:		fclean test_step_0

test_step_0:$(GTEST_OBJS) $(TEST_OBJS)
			make DEBUG=1 $(NAME)
			echo "$(BLUE)\ntest linking$(RESET)"
			$(CXX) -L $(LIB_DIR) -lft -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJS) $(GTEST_OBJS) -o $(TEST_NAME)
			./$(TEST_NAME)
			$(RM) $(TEST_NAME)

$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.cpp
			mkdir -p $(@D)
			$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I ./libft/inc -I ./inc -c $< -o $@
			printf "$(GREEN).$(RESET)"

##########################################
$(GTEST_OBJS): $(GTEST_SRCS_DIR)
			echo "$(BLUE)test compiling$(RESET)"
			mkdir -p $(@D)
			$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I ./inc/ -c $(GTEST_SRCS_DIR)/gtest-all.cc -o $(TEST_OBJS_DIR)/gtest-all.o
			printf "$(GREEN).$(RESET)"
			$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I ./inc/ -c $(GTEST_SRCS_DIR)/gtest_main.cc -o $(TEST_OBJS_DIR)/gtest_main.o
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

##########################################
.PHONY:		test_clean
test_clean:
			@echo "$(BLUE)test cleaning$(RESET)"
			$(RM) -r $(TEST_OBJS_DIR)

.PHONY:		retest
retest:		test_clean test
