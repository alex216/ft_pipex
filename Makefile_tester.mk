# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_tester.mk                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yliu <yliu@student.42.jp>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:53:08 by yliu              #+#    #+#              #
#    Updated: 2024/05/04 22:57:54 by yliu             ###   ########.fr        #
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
GTEST_FUSE		:= fuse_gtest_files.py
GTEST_FUSE_URL	:= https://raw.githubusercontent.com/google/googletest/ec44c6c1675c25b9827aacd08c02433cccde7780/googletest/scripts/$(GTEST_FUSE)

##########################################
# directory
TEST_SRCS_DIR	:= ./test/unit
GTEST_SRCS_DIR	:= ./test/unit/gtest
TEST_OBJS_DIR	:= ./test/obj

##########################################
# src files
GTEST_SRCS		:= $(GTEST_SRCS_DIR)/gtest_main.cc \
				  $(GTEST_SRCS_DIR)/gtest-all.cc

TEST_SRCS		:= $(TEST_SRCS_DIR)/test_cmds.cpp \
				   $(TEST_SRCS_DIR)/test_parse.cpp \
				   $(TEST_SRCS_DIR)/test_heredoc.cpp

# obj files
TEST_OBJS		:= $(subst $(TEST_SRCS_DIR), $(TEST_OBJS_DIR), $(TEST_SRCS:.cpp=.o))
GTEST_OBJS		:= $(subst $(GTEST_SRCS_DIR), $(TEST_OBJS_DIR), $(GTEST_SRCS:.cc=.o))
OBJ_FILTER_MAIN	:= $(filter-out $(OBJS_DIR)/main.o, $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)))

TEST_FILE_NUM	= $(words $(TEST_SRCS))
# DIFF_LINE		= $(shell yes $- | head -n $(DIFF) | tr -d '\n'; echo)

##########################################
.PHONY:		test
test:		test_step_0

.PHONY:		test_step_0
test_step_0:$(NAME) $(GTEST_OBJS)
			@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(TEST_NAME)]\ttest files \t$(WHITE)checking...$(DEF_COLOR)\n"
			@$(ECHO)  "\e$(GRAY)$(LINE)\r$(DEF_COLOR)"
			@make -s test_step_1

.PHONY:		test_step_1
test_step_1:$(TEST_OBJS)
			@$(ECHO)  "\r\e$(GREEN)$(LINE)$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) ‣ 100%% $(DEF_COLOR)\n"
			@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(TEST_NAME)]\ttest files \t$(GREEN)compiled ✓$(DEF_COLOR)\n"
			@$(CXX) -L $(LIB_DIR) -lft -lpthread $(OBJ_FILTER_MAIN) $(TEST_OBJS) $(GTEST_OBJS) -o $(TEST_NAME)
			@./$(TEST_NAME)
			@$(RM) $(TEST_NAME)

$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.cpp
			@mkdir -p $(@D)
			@$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) $(foreach dir_element,$(MAN_INC_DIR),-I$(dir_element)) -c $< -o $@
			make -s output_diff_test

ITER			= 0
DIFF			= 0
PREV			= 0
.PHONY:			output_diff_test
output_diff_test:
				$(eval ITER=$(shell echo $$(($(ITER) + 1))))
				$(eval NEW=$(shell echo $$(($(ITER) * $(BAR_LEN) / $(TEST_FILE_NUM)))))
				$(eval DIFF=$(shell echo $$(($(NEW) - $(PREV)))))
				$(eval PREV=$(shell echo $$(($(NEW)))))
				@$(ECHO) "$(RED)$(DIFF_LINE)$(DEF_COLOR)"

##########################################
$(GTEST_OBJS): $(GTEST_SRCS_DIR)
			@mkdir -p $(@D)
			@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(TEST_NAME)]\tgtest configs\t$(WHITE)checking...$(DEF_COLOR)\n"
			@$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I $(INC_DIR) -c $(GTEST_SRCS_DIR)/gtest-all.cc -o $(TEST_OBJS_DIR)/gtest-all.o
			@$(CXX) $(CXXFLAGS) -I $(TEST_SRCS_DIR) -I $(INC_DIR) -c $(GTEST_SRCS_DIR)/gtest_main.cc -o $(TEST_OBJS_DIR)/gtest_main.o
			@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(TEST_NAME)]\tgtest configs\t$(GREEN)compiled ✔$(DEF_COLOR)\n"


$(GTEST_SRCS_DIR):
			$(ECHO) "fetching google test"
			curl -#OL $(GTEST_REPO_URL)
			$(ECHO) "fetching fuse_gtest_files.py"
			curl -#OL $(GTEST_FUSE_URL)
			tar -xzf $(GTEST_ARCHIVE) $(GTEST_SRC_DIR)
			python3 $(GTEST_FUSE) $(GTEST_SRC_DIR)/googletest $(GTEST_SRCS_DIR)
			mv $(GTEST_SRC_DIR)/googletest/src/gtest_main.cc $(GTEST_SRCS_DIR)
			mv $(GTEST_SRCS_DIR)/gtest/* $(GTEST_SRCS_DIR)
			$(RM) -r $(GTEST_SRC_DIR) $(GTEST_SRCS_DIR)/gtest $(GTEST_ARCHIVE) $(GTEST_FUSE)

##########################################
.PHONY:		test_clean
test_clean:
			@$(RM) -r $(TEST_OBJS_DIR)
			@$(ECHO) "$(DEF_COLOR)$(BLUE)[$(TEST_NAME)]\tobject files \t$(GREEN)deleted ✓$(DEF_COLOR)\n"

.PHONY:		retest
retest:		test_clean test
