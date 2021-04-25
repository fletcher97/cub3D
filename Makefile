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

NAME = cub3D

# MLX_LIB_LINUX = ${MLX_LIB_LINUX_ROOT}libmlx_x86_64.a

LIBFT_ROOT = ${LIB_ROOT}libft/
LIBFT_INC = ${LIBFT_ROOT}inc/
LIBFT = ${LIBFT_ROOT}bin/libft.a

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

# Minilibx to be selected when running in mac.
# Possible values are: mms, opengl (default: mms)
MLX = opengl

################################################################################
# Compiler & Flags
################################################################################

CC = gcc

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g

################################################################################
# Folders & Files
################################################################################

BIN_ROOT = bin/
SRC_ROOT = src/
LIB_ROOT = lib/
INC_ROOT = inc/
OBJ_ROOT = obj/
DEP_ROOT = dep/
TESTS_ROOT = tests/

DIRS = error/ graphics/ map/ player/

SRC_DIRS := $(addprefix ${SRC_ROOT}, ${DIRS})
OBJ_DIRS := $(addprefix ${OBJ_ROOT}, ${DIRS})
DEP_DIRS := $(addprefix ${DEP_ROOT}, ${DIRS})
INC_DIRS := ${INC_ROOT} ${LIBFT_INC}

SRCS := $(foreach dir, ${SRC_DIRS}, $(wildcard ${dir}*.c))
SRCS += $(wildcard ${SRC_ROOT}*.c)
OBJS := $(subst ${SRC_ROOT}, ${OBJ_ROOT}, ${SRCS:.c=.o})
DEPS := $(subst ${SRC_ROOT}, ${DEP_ROOT}, ${SRCS:.c=.d})

INCS := ${addprefix -I, ${INC_DIRS}}


TESTS := $(wildcard ${TESTS_ROOT}*.c)

BINS := ${BIN_ROOT}${NAME}
TEST := ${TESTS_ROOT}mytest

################################################################################
# VPATHS
################################################################################

vpath %.o $(OBJ_ROOT)
vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)
vpath %.d $(DEP_DIRS)

################################################################################
# Conditions
################################################################################

ifeq ($(shell uname), Linux)
	MLX_LIB_ROOT := ${LIB_ROOT}minilibx-linux/
	MLX_LIB := ${MLX_LIB_ROOT}libmlx.a
	INCS += $(addprefix -I, ${MLX_LIB_ROOT})
	LIBS := -L${MLX_LIB_ROOT} -lmlx
	LIBS += -L${LIBFT_ROOT}bin -lft
	LIBS += -L/usr/lib -lXext -lX11 -lm -lz
	SED := sed -i.tmp --expression
	SED_END = && rm -f $@.tmp
else ifeq ($(shell uname), Darwin)
	LIBS := -L${LIBFT_ROOT}bin -lft
	ifeq (${MLX}, opengl)
		MLX_LIB_ROOT := ${LIB_ROOT}minilibx_opengl_20191021/
		LIBS += -L${MLX_LIB_ROOT} -lmlx
		LIBS += -framework OpenGL -framework AppKit -lz
		MLX_LIB := ${MLX_LIB_ROOT}libmlx.dylib
	else ifeq (${MLX}, mms)
		MLX_LIB_ROOT := ${LIB_ROOT}minilibx_mms_20200219/
		LIBS += -L${MLX_LIB_ROOT} -lmlx
		MLX_LIB := ${MLX_LIB_ROOT}libmlx.a
	endif
	INCS += $(addprefix -I, ${MLX_LIB_ROOT})
	SED = sed -i.tmp
	SED_END = && rm -f $@.tmp
endif

ifeq (${VERBOSE},0)
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

${BINS}: ${LIBFT} ${MLX_LIB} ${OBJS}
	${AT}printf "\033[38;5;46m[CREATING ${NAME} ]\033[0m\n" ${BLOCK}
	${AT}mkdir -p ${BIN_ROOT}
	${AT}${CC} ${CFLAGS} ${INCS} ${OBJS} ${LIBS} -o ${BIN_ROOT}${@F}


${LIBFT}:
	${AT}make -C ${LIBFT_ROOT} ${BLOCK}

${MLX_LIB}:
	${AT}make -C ${MLX_LIB_ROOT}

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
	make clean_all -C ${LIBFT_ROOT}

re: fclean all

################################################################################
# Debug Targets
################################################################################

debug: CFLAGS += ${DFLAGS}
debug: ${LIBFT} ${MLX_LIB} ${OBJS}

debug_re: fclean debug

################################################################################
# Test Targets
################################################################################

testre: debug_re ${TEST}

testm: debug ${TEST}
	${AT}printf "\033[33m[RUNNING TEST]\033[0m\n" ${BLOCK}
	${AT}./${TEST}

testv: debug ${TEST}
	${AT}printf "\033[33m[RUNNING TEST]\033[0m\n" ${BLOCK}
	${AT}valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -v ./${TEST}
${TEST}: CFLAGS += ${DFLAGS}
${TEST}:
	${AT}printf "\033[38;5;46m[GENERATING TEST]\033[0m\n" ${BLOCK}
	${AT}${CC} ${CFLAGS} ${INCS} ${OBJS} ${LIBS} -o $@


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
	$${AT}rm -f $$@
	$${AT}$${CC} -MM $$< $${INCS} -MF $$@
	$${AT}$${SED} 's|:| $$@ :|' $$@ $${SED_END}
	$${AT}$${SED} '1 s|^|$${@D}/|' $$@ $${SED_END}
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
