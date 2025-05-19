NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
OBJDIR=objs/

SRCS=ft_printf.c ft_puts.c print_select1.c print_select2.c

.PHONY: all clean fclean re

OBJS = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS))

all: ft_printf.h $(OBJDIR) $(OBJS) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
