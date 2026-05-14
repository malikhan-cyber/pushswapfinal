NAME = push_swap
BONUSNAME = checker
FLAGS = -Werror -Wall -Wextra
BIN = ./bin/
CC = cc
BASESRCS = operations/push.c \
		   operations/reverse_rotate.c \
		   operations/rotate.c \
		   operations/swap.c \
		   stack/list_contents.c \
		   stack/list_utils.c \
		   stack/parsing.c \
		   stack/position_utils.c \
		   stack/stack.c
PSWSRCS = $(BASESRCS) \
		  adaptive_sorting.c \
		  complex/complex_sorting.c \
		  complex/pivots.c \
		  complex/quicksort_utils.c \
		  main.c \
		  medium/medium_sorting.c \
		  medium/medium_sort_merge.c \
		  simple/insertion.c \
		  simple/insertion_sort.c \
		  simple/simple_sorting.c
CHKSRCS = $(BASESRCS) \
		  main_bonus.c \
		  gnl/get_next_line.c \
		  gnl/get_next_line_utils.c
PSWOBJS = $(PSWSRCS:%.c=$(BIN)%.o)
CHKOBJS = $(CHKSRCS:%.c=$(BIN)%.o)
LIB = $(BIN)libft.a
LIBDIR = /

all: $(NAME)

$(NAME): $(PSWOBJS) $(LIB)
	$(CC) $(PSWOBJS) $(LIB) $(FLAGS) -o $(NAME)

$(BONUSNAME): $(CHKOBJS) $(LIB)
	$(CC) $(CHKOBJS) $(LIB) $(FLAGS) -o $(BONUSNAME)

$(BIN)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) -g -o $@ $<

.PHONY: all fclean clean re clean/%.a fclean/%.a

$(LIB): $(shell find $(basename $(notdir $(LIB))) -name '*.c' -or -name '*.h' -or -name 'Makefile')
	make -C $(basename $(notdir $(LIB)))
	cp $(basename $(notdir $(LIB)))/$(notdir $@) $@

bonus: FLAGS += -D CHECKER_BONUS
bonus: $(BONUSNAME)

re: fclean all

clean:
	rm $(BIN) -rf
	make -C $(basename $(notdir $(LIB))) fclean

fclean: clean
	rm $(name) -f
