NAME = parse

SRCS = 	gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		init/init_mlx.c \
		check/check_if_close.c \
		check/check_map.c \
		check/check_utils.c \
		check/check_name.c \
		check/check_all.c \
		draw/draw.c \
		move/move_all.c \
		catch_size.c \
		ft_split.c \
		utils.c \
		get_opt.c \
		main.c
				
OBJS 		= 	${SRCS:.c=.o}

PATH_MLX	=	./mlx
CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror -g3 #-fsanitize=address
RM			= 	rm -f
NAME		= 	parse
FLAGS		=	-ldl -Imlx -Lmlx -lmlx -lm -lXext -lX11

all: 			${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS)
				@make -C $(PATH_MLX)
				${CC} $(CFLAGS) $(OBJS) $(FLAGS) -o $(NAME)


clean:
				make -C $(PATH_MLX) clean
				${RM} ${OBJS}

fclean: 		clean
				${RM} ${NAME}

re: 			fclean all

.SILENT:		$(NAME)

.PHONY:			all clean fclean re