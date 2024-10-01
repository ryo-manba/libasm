NAME = libasm.a

SRCS = ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s

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
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

dump:
	objdump -D a.out

debug: CFLAGS += -g -fsanitize=address
debug: re
	$(CC) $(CFLAGS) main.c $(NAME)  && ./a.out

.PHONY: all clean fclean re dump debug