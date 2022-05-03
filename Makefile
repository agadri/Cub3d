NAME = parse

SRCS = 	gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		check/check_if_close.c \
		check/check_utils.c \
		catch_size.c \
		ft_split.c \
		utils.c \
		get_opt.c \
		main.c
				
OBJS 		= 	${SRCS:.c=.o}

CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g3 #-fsanitize=address
RM			= 	rm -f
NAME		= 	parse

all: 			${NAME}

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS)
				${CC} $(CFLAGS) $(OBJS) -o $(NAME)


clean:
				${RM} ${OBJS}

fclean: 		clean
				${RM} ${NAME}

re: 			fclean all

.SILENT:		$(NAME)

.PHONY:			all clean fclean re