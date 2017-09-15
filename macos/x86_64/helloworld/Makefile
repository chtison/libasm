.PHONY: all clean fclean re

NAME := helloworld
OBJS := main.o

all: $(NAME)

$(NAME): $(OBJS)
	ld $^ -o $@ -macosx_version_min 10.8 -lSystem

%.o: %.s
	nasm -f macho64 -Wall -o $@ $<

clean:
	rm -f -- $(NAME)

fclean: clean
	rm -f -- $(OBJS)

re: fclean all
