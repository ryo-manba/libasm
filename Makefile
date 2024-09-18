NAME = libasm.a

SRCS = ft_strlen.s \
			ft_strcpy.s

OBJS = $(SRCS:.s=.o)

NASM = nasm
NASMFLAGS = -f macho64

CC = gcc

ifeq ($(shell uname -m), arm64)
	CC += -ld_classic --target=x86_64-apple-darwin
endif

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.s
	@$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) $(NAME) main.c && ./a.out

dump:
	objdump -D a.out

.PHONY: all clean fclean re dump