################################################################################
# Makefile
################################################################################

# Makefile by fletcher97
# Version: 1.2

# This makefile can be copied to a directory and it will generate the file
# structure and initialize a git repository with the .init rule. Any variables
# and rules for the specifique project can be added in the appropriate section.

################################################################################
# Project Variables
################################################################################

NAME = ...

################################################################################
# Configs
################################################################################

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE = 1

################################################################################
# Compiler & Flags
################################################################################

CC = gcc

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g -fsanitize=address

################################################################################
# Folders & Files
################################################################################

BIN_ROOT = bin/
SRC_ROOT = src/
INC_ROOT = inc/
OBJ_ROOT = obj/
DEP_ROOT = dep/
TESTS_ROOT = tests/

DIRS = ...

SRC_DIRS := $(addprefix ${SRC_ROOT}, ${DIRS})
OBJ_DIRS := $(addprefix ${OBJ_ROOT}, ${DIRS})
DEP_DIRS := $(addprefix ${DEP_ROOT}, ${DIRS})

SRCS := $(foreach dir, ${SRC_DIRS}, $(wildcard ${dir}*.c))
SRCS += $(wildcard ${SRC_ROOT}*.c)
OBJS := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS:.c=.o})
DEPS := $(subst ${SRC_ROOT}, ${DEP_ROOT}, ${SRCS:.c=.d})

TESTS := $(wildcard ${TESTS_ROOT}*.c)

INCS := -I ${INC_ROOT}

BINS := ${BIN_ROOT}${NAME}
TEST := ${TESTS_ROOT}mytest

################################################################################
# VPATHS
################################################################################

vpath %.o $(OBJ_ROOT)
vpath %.h $(INC_ROOT)
vpath %.c $(SRC_DIRS)
vpath %.d $(DEP_DIRS)

################################################################################
# Conditions
################################################################################

ifeq ($(VERBOSE),0)
	MAKEFLAGS += --silent
	BLOCK = >/dev/null
else ifeq ($(VERBOSE),1)
	MAKEFLAGS += --silent
else ifeq ($(VERBOSE),2)
	AT = @
else ifeq ($(VERBOSE),4)
	MAKEFLAGS += --debug=v
endif

################################################################################
# Project Target
################################################################################

all: ${BINS}

${BINS}: ${OBJS}
	${AT}printf "\033[38;5;46m[CREATING LIBFT ARCHIVE]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}cd ${BIN_ROOT}; ${AR} ${@F} $(addprefix ../, ${OBJS})

################################################################################
# Setup Target
################################################################################

.init:
	${AT}printf "\033[33m[CREATING FOLDER STRUCTURE]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}mkdir -p ${DEP_ROOT}
	${AT}mkdir -p ${INC_ROOT}
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}mkdir -p ${SRC_ROOT}
	${AT}mkdir -p ${TESTS_ROOT}
	${AT}printf "\033[33m[INITIALIZING GIT REPOSITORY]\033[0m\n" ${BLOCK}
	${AT}git init
	${AT}echo "*.o\n*.d\n.vscode\na.out\n.init\n.DS_Store" > .gitignore
	${AT}date > $@

################################################################################
# Clean Targets
################################################################################

clean:
	${AT}printf "\033[38;5;1m[REMOVING OBJECTS]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT}
	${AT}find ${OBJ_ROOT} -type f -delete 2>/dev/null

fclean: clean
	${AT}printf "\033[38;5;1m[REMOVING BINARIES]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}find ${BIN_ROOT} -type f -delete

clean_dep:
	${AT}printf "\033[38;5;1m[REMOVING DEPENDENCIES]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${DEP_ROOT}
	${AT}find ${DEP_ROOT} -type f -delete 2>/dev/null

clean_all: clean_dep fclean

re: fclean all

################################################################################
# Debug Targets
################################################################################

debug: CFLAGS += ${DFLAGS}
debug: all

debug_re: fclean debug

################################################################################
# Test Targets
################################################################################

testre: debug_re ${TEST}

testm: debug ${TEST}

${TEST}: CFLAGS += ${DFLAGS}
${TEST}:
	${AT}printf "\033[38;5;46m[GENERATING TEST]\033[0m\n" ${BLOCK}
	${AT}${CC} ${CFLAGS} ${INCS} ${TESTS} ${BIN_ROOT}/${NAME} -o $@
	${AT}printf "\033[33m[RUNNING TEST]\033[0m\n" ${BLOCK}
	${AT}./$@

################################################################################
# .PHONY
################################################################################

.PHONY : clean fclean clean_dep clean_all re all testre testm ${TEST}

################################################################################
# Function
################################################################################

define make_obj
${1} : ${2} ${3}
	$${AT}printf "\033[38;5;14m[OBJ]: \033[38;5;47m$$@\033[0m\n" ${BLOCK}
	$${AT}mkdir -p $${@D}
	$${AT}$${CC} $${CFLAGS} $${INCS} -c $$< -o $$@
endef

define make_dep
${1} : ${2}
	$${AT}printf "\033[38;5;13m[DEP]: \033[38;5;47m$$@\033[0m\n" ${BLOCK}
	$${AT}mkdir -p $${@D}
	$${AT}$${CC} -MM $$< -I $${INC_ROOT} -MF $$@
	$${AT}sed -i.tmp --expression 's|:| $$@ :|' $$@ && rm $$@.tmp
	$${AT}sed -i.tmp --expression '1 s|^|$${@D}/|' $$@ && rm $$@.tmp
endef

################################################################################
# Function Generator
################################################################################

$(foreach src, $(SRCS), $(eval \
$(call make_dep, $(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)), $(src))))

$(foreach src, $(SRCS), $(eval \
$(call make_obj, $(subst ${SRC_ROOT}, ${OBJ_ROOT}, $(src:.c=.o)), \
$(src), \
$(subst ${SRC_ROOT}, ${DEP_ROOT}, $(src:.c=.d)))))

################################################################################
# Includes
################################################################################

-include ${DEPS}
