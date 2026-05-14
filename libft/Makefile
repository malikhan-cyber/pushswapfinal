NAME = libft.a
FLAGS = -Werror -Wall -Wextra
BIN = ./bin/
EX = cc
SRCS = ft_case.c ft_is_char.c ft_mem.c ft_mem_cmp.c ft_string.c ft_string2.c ft_string3.c ft_ints.c ft_strmapi.c ft_put_fd.c ft_list.c ft_list_mut.c ft_max.c pf_alignment_bonus.c pf_flags.c pf_formatting_bonus.c pf_print_base.c pf_print_char.c pf_printf.c pf_print_hex.c pf_print_int.c pf_print_percent.c pf_print_pointer.c pf_print_string.c pf_print_uint.c pf_print_float.c pf_print_float_integer.c pf_print_float_fractional.c pf_put.c pf_values.c
OBJS = $(SRCS:%.c=$(BIN)%.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(BIN)%.o: %.c
	mkdir -p $(BIN)
	$(EX) -c $(FLAGS) -g -o $@ $< -D PRINTF_BONUS

.PHONY: all fclean clean re 

re: fclean all

bonus: all

clean:
	 rm $(BIN) -r -f

fclean: clean
	 rm $(NAME) -f
