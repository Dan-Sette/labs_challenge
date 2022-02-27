SRC_FILES	=	main.c mongoose.c ft_substr.c ft_split.c ft_calloc.c \
				ft_strlcpy.c log.c do_free.c ft_strjoin.c ft_itoa.c \
				ft_strdup.c log_utils.c

SRC_DIR		=	./src
OBJECT_DIR	=	./obj
INCLUDES	=	./includes

OBJECT		=	$(addprefix $(OBJECT_DIR)/,$(subst .c,.o,$(SRC_FILES)))
CC			=	clang
CFLAGS		=	-g3 -Wall -Wextra -Werror -fsanitize=address
MAKE_DIR	=	mkdir -p
RM			=	rm -fr
NAME		=	labs_challenge

all:				$(NAME)

$(NAME):			$(OBJECT)
		$(CC) $(CFLAGS) -g -I $(INCLUDES) $(OBJECT) -o $(NAME) -lcurl

$(OBJECT_DIR)/%.o:	$(SRC_DIR)/%.c
		$(MAKE_DIR) $(OBJECT_DIR)
		$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
		$(RM) $(OBJECT_DIR)

fclean:	clean
		$(RM) $(NAME)

re:	fclean	all

val:
		valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes --trace-children=yes --log-file=valgrind-out.txt ./labs_challenge
#		valgrind --leak-check=full --show-leak-kinds=all --tool=drd -s --track-origins=yes --log-file=valgrind-out.txt ./labs_challenge

.PHONY: all clean fclean re val