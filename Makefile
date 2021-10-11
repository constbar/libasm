SRCS =	ft_strlen.s ft_strcpy.s ft_write.s ft_read.s ft_strcmp.s ft_strdup.s

OBJ = $(SRCS:.s=.o)

NAME = libasm.a

FLAGS = -f macho64

GCC = nasm

RM = rm -f

%.o: %.s
	$(GCC) $(FLAGS) $<

$(NAME): $(OBJ) 
		ar rc $(NAME) $(OBJ)

all: $(NAME)

test: $(NAME)
	gcc -Wall -Wextra -Werror main.c $(NAME) -o test

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) libasm.a

re: fclean all

.PHONY: all clean fclean re
