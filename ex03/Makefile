# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 16:22:14 by dande-je          #+#    #+#              #
#    Updated: 2025/03/14 17:58:35 by dande-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                REQUIREMENTS                                  #
#******************************************************************************#

GOOGLETEST_VERSION              := 1.8.1

#******************************************************************************#
#                                   COLOR                                      #
#******************************************************************************#

RED                             := \033[0;31m
GREEN                           := \033[0;32m
YELLOW                          := \033[0;33m
PURPLE                          := \033[0;35m
CYAN                            := \033[0;36m
RESET                           := \033[0m

#******************************************************************************#
#                                   PATH                                       #
#******************************************************************************#

SRCS_DIR                        := src/
SRCS_MAIN_DIR                   := $(SRCS_DIR)main/
SRCS_CORE_DIR                   := $(SRCS_DIR)core/
SRCS_FIXED_DIR                  := $(SRCS_CORE_DIR)fixed/
SRCS_POINT_DIR                  := $(SRCS_CORE_DIR)point/
INCS                            := src/
BIN_DIR                         := bin/
BUILD_DIR                       := build/
TEST_DIR                        := test/
TEST_CORE_DIR                   := $(TEST_DIR)core/
TEST_FIXED_DIR                  := $(TEST_CORE_DIR)fixed/
BIN_TEST_DIR                    := $(TEST_DIR)bin/
BUILD_TEST_DIR                  := $(TEST_DIR)build/
GOOGLETEST_DIR                  := $(TEST_DIR)extern/googletest/
GOOGLETEST_BUILD_DIR            := $(GOOGLETEST_DIR)build/
GOOGLETEST_INCS                 := $(GOOGLETEST_DIR)googletest/include/ $(TEST_DIR)
GOOGLETEST_LIBS                 := $(GOOGLETEST_BUILD_DIR)googlemock/gtest/

#******************************************************************************#
#                                  COMMANDS                                    #
#******************************************************************************#

RM                              := rm -rf
MKDIR                           := mkdir -p
MAKEFLAGS                       += --no-print-directory
SLEEP                           := sleep 0.01

#******************************************************************************#
#                                   FILES                                      #
#******************************************************************************#

TEST_LIBS                       := $(GOOGLETEST_LIBS)libgtest.a \
								   $(GOOGLETEST_LIBS)libgtest_main.a

NAME_OUTPUT                     = fixed
NAME                            = $(BIN_DIR)$(NAME_OUTPUT)

SRCS_FILES                      += $(addprefix $(SRCS_MAIN_DIR), main.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_FIXED_DIR), FixedArithmetic.cpp \
								   FixedConstructors.cpp \
								   FixedUtility.cpp)
SRCS_FILES                      += $(addprefix $(SRCS_POINT_DIR), PointConstructor.cpp \
								   PointUtility.cpp \
								   bsp.cpp)

OBJS                            += $(SRCS_FILES:%.cpp=$(BUILD_DIR)%.o)

TEST_OUTPUT                     = test_fixed
TEST_NAME                       = $(BIN_TEST_DIR)$(TEST_OUTPUT)

TEST_FILES                      += $(addprefix $(TEST_DIR), test_main.cpp)
TEST_FILES                      += $(addprefix $(TEST_FIXED_DIR), test_arithmetic.cpp \
								   test_constructor.cpp \
								   test_utility.cpp)

TEST_OBJS                       += $(TEST_FILES:%.cpp=$(BUILD_TEST_DIR)%.o)

DEPS                            += $(OBJS:.o=.d)

#******************************************************************************#
#                               OUTPUTS MESSAGES                               #
#******************************************************************************#

COUNT                           = 0
OBJS_COUNT                      = 0
MATH                            = 0
CLEAN_MESSAGE                   := $(NAME_OUTPUT) objects deleted
FCLEAN_MESSAGE                  := $(NAME_OUTPUT) deleted
FCLEAN_TEST_MESSAGE             := $(TEST_OUTPUT) deleted
EXE_MESSAGE                     = $(RESET)[100%%] $(GREEN)Built target $(NAME_OUTPUT)
TEST_EXE_MESSAGE                = $(RESET)[100%%] $(GREEN)Built target $(TEST_OUTPUT)
COMP_MESSAGE                    = Building CPP object

#******************************************************************************#
#                               COMPILATION                                    #
#******************************************************************************#

CC                             := c++
CFLAGS                         = -Wall -Wextra -Werror -Ofast -Wunreachable-code -Wpedantic -std=c++98
CPPFLAGS                       := $(addprefix -I,$(INCS)) -MMD -MP
DFLAGS                         := -Wall -Wextra -Werror -g3 -std=c++98
LFLAGS                         := -march=native
COMPILE_OBJS                   = $(CC) $(CFLAGS) $(LFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE                    = $(CC) $(CFLAGS) $(OBJS) -o $(NAME)
TEST_CFLAGS                    = -std=c++98
TEST_CPPFLAGS                  := $(addprefix -I,$(GOOGLETEST_INCS)) $(addprefix -I,$(INCS))
TEST_LFLAGS                    := -L$(GOOGLETEST_LIBS) -lgtest -lgtest_main -pthread
COMPILE_OBJS_TEST              = $(CC) $(TEST_CFLAGS) $(TEST_CPPFLAGS) -c $< -o $@
COMPILE_TEST_EXE               = $(CC) $(TEST_CFLAGS) $(TEST_OBJS) $(filter-out $(BUILD_DIR)$(SRCS_MAIN_DIR)main.o, $(OBJS)) -o $(TEST_NAME) $(TEST_LFLAGS)

#******************************************************************************#
#                                   DEFINE                                     #
#******************************************************************************#

ifdef WITH_DEBUG
	CFLAGS                     = $(DFLAGS)
endif

#******************************************************************************#
#                                  FUNCTION                                    #
#******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define submodule_update_googletest
	# $(RM) $(GOOGLETEST_DIR)
	printf "$(PURPLE)Building library googletest $(GOOGLETEST_VERSION)\n$(RESET)"
	git submodule update --init --recursive >/dev/null 2>&1 || true
	git submodule foreach -q --recursive \
		'branch="$(git config -f $toplevel/.gitmodules submodule.googletest)"; \
		git pull origin main; \
		git fetch; \
		git checkout release-$(GOOGLETEST_VERSION)' \
		>/dev/null 2>&1 || true
	$(SLEEP)
	$(MKDIR) $(GOOGLETEST_BUILD_DIR) >/dev/null 2>&1 || true
	cd $(GOOGLETEST_BUILD_DIR) && cmake -DCMAKE_CXX_FLAGS="-std=c++98 -w" .. && make
	$(SLEEP)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMPILE_OBJS)
	$(eval MATH=$(shell expr "$(COUNT)" \* 100 \/ "$(OBJS_COUNT)"))
	$(eval MATH=$(shell if [ $(COUNT) -lt 1 ]; then echo $(shell expr "$(MATH)" + 100) ; else echo $(MATH) ; fi))
	printf "[%3d%%] $(YELLOW)$(COMP_MESSAGE) $@ \r$(RESET)\n" $$(echo $(MATH))
endef

define comp_exe
	$(MKDIR) $(BIN_DIR)
	$(COMPILE_EXE)
	$(SLEEP)
	printf "$(EXE_MESSAGE)\n$(RESET)"
endef

define comp_test
	$(MKDIR) $(BIN_TEST_DIR)
	$(COMPILE_TEST_EXE)
	$(SLEEP)
	printf "$(TEST_EXE_MESSAGE)\n$(RESET)"
	./$(TEST_NAME)
endef

define clean
	$(RM) $(BUILD_DIR)
	$(SLEEP)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
endef

define fclean
	$(RM) $(BIN_DIR)
	$(RM) $(BIN_TEST_DIR)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
endef

define test_fclean
	$(RM) $(BIN_DIR)
	$(RM) $(BUILD_DIR)
	printf "$(RED)$(CLEAN_MESSAGE)$(RESET)\n"
	printf "$(RED)$(FCLEAN_MESSAGE)$(RESET)\n"
	$(RM) $(BUILD_TEST_DIR)
	$(RM) $(BIN_TEST_DIR)
	$(SLEEP)
	printf "$(RED)$(FCLEAN_TEST_MESSAGE)$(RESET)\n"
endef

define debug
	$(call clean)
	$(call fclean)
	$(MAKE) WITH_DEBUG=TRUE
endef

define reset_count
	$(eval COUNT=$(1))
	$(eval OBJS_COUNT=$(words $(SRCS_FILES)))
endef

#******************************************************************************#
#                                   TARGETS                                    #
#******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %.cpp
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(call reset_count, -$(words $(OBJS))) $(OBJS)
	$(call comp_exe)

$(TEST_LIBS):
	$(call submodule_update_googletest)

$(BUILD_TEST_DIR)%.o: %.cpp
	$(call create_dir)
	$(COMPILE_OBJS_TEST)

test: test_fclean $(TEST_LIBS) $(call reset_count, -$(words $(OBJS))) $(OBJS) $(TEST_OBJS)
	$(call comp_test)

test_fclean:
	$(call test_fclean)

clean:
	$(call clean)

fclean: clean
	$(call fclean)

re: fclean all

debug:
	$(call debug)

.PHONY: all clean fclean re debug test googletest test_fclean
.DEFAULT_GOAL := all
.SILENT:

