##
## EPITECH PROJECT, 2021
## EatSleepCode
## File description:
## make the EatSleepCode
##

# ----------------------------------------------------------------------------
# TARGET
ifndef
NAME		=	EatSleepCode
endif
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# COLOUR
CYAN		=	'\033[1;36m'
BLUE		=	'\033[1;34m'
GREEN 		= 	'\033[1;32m'
RED			=	'\033[1;31m'

RESET		=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# IN-MAKEFILE SETTINGS
CURR_RULE	=	all
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# SRC
SRCDIR		:=	src/

SRC			:=	src/main.c						\
				src/argparse.c					\
				src/file/destroy.c				\
				src/file/display.c				\
				src/file/getfile.c				\
				src/graphics/create_window.c	\
				src/graphics/destroy_window.c	\
				src/graphics/esp.c				\
				src/graphics/handle_event.c

OBJ			:=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# LIB
LIB_TARGET	=	lib/libmy.a

LDFLAGS		=	-L$(dir $(LIB_TARGET)) -lmy -lcsfml-graphics
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# TEST
TNAME		:=	bin_test

TSRCDIR		:=	tests/

TSRC		:=	test_basic.c
TSRC		:=	$(addprefix $(TSRCDIR),$(TSRC))
TSRC		:= 	$(filter-out $(SRCDIR)main.c,$(SRC)) $(TSRC)

TOBJ		:=	$(TSRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# FLAGS
CFLAGS		= 	-Iinclude/ -Ilib/include/ -Wall -Wextra -Wpedantic

TFLAGS		=	-fprofile-arcs -ftest-coverage

CR_TEST_LDFLAGS	=	-lcriterion -lgcov

FN_TEST_LDFLAGS	=	-lgcov
# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@echo -e $(BLUE)'compil : $(notdir $^) -> $(notdir $@)'$(RESET)

# ----------------------------------------------------------------------------
# Make the EatSleepCode
.PHONY: 	all
all:		CURR_RULE = all
all:		init $(LIB_TARGET)
	@$(MAKE) $(NAME) -s
	@echo -e $(GREEN)'-> [finished]: $(NAME): all'$(RESET)

$(NAME):	CURR_RULE = $(NAME)
$(NAME): 	init $(OBJ)
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(NAME)'$(RESET)

debug: CFLAGS += -g3
debug: fclean $(LIB_TARGET) $(NAME)

$(LIB_TARGET):
	@$(MAKE) -s -C $(dir $(LIB_TARGET))
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Mr. clean
.PHONY: 	clean
clean:
	@$(RM) $(OBJ) $(TOBJ)
	@$(RM) $(TOBJ:.o=.gcno) $(TOBJ:.o=.gcda) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	@$(RM) vgcore.*

.PHONY: 	fclean
fclean:		CURR_RULE = fclean
fclean:		init clean
	@$(MAKE) -C $(dir $(LIB_TARGET)) fclean -s
	@$(RM) $(NAME) $(TNAME)
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(CURR_RULE)'$(RESET)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Re
.PHONY: 	re
re:		CURR_RULE = re
re:		init
	@$(MAKE) fclean -s
	@$(MAKE) all -s
	@echo -e $(GREEN)'-> [finished]: $(NAME): $(CURR_RULE)'$(RESET)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Test
.PHONY: tests_run
tests_run: cr_tests_run

.PHONY: cr_tests_run
cr_tests_run: LDFLAGS += $(CR_TEST_LDFLAGS)
cr_tests_run: CFLAGS += $(TFLAGS)
cr_tests_run: fclean $(LIB_TARGET) $(TOBJ)
	@$(CC) $(TOBJ) -o $(TNAME) $(LDFLAGS) $(LDFLAGS) $(CFLAGS)
	@./$(TNAME)
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branch

.PHONY: fn_tests_run
fn_tests_run: LDFLAGS += $(FN_TEST_LDFLAGS)
fn_tests_run: CFLAGS += $(TFLAGS)
fn_tests_run: fclean $(LIB_TARGET) $(OBJ)
	@$(CC) $(OBJ) -o $(TNAME) $(LDFLAGS) $(CFLAGS)
	@./tests/fn_tests.sh ./$(TNAME)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# Prety Print
.PHONY: init
init:
	@echo -e $(CYAN)'-> [starting]: $(NAME): make $(CURR_RULE)'$(RESET)
# ----------------------------------------------------------------------------
