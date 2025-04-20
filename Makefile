# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 19:40:08 by nfoughal          #+#    #+#              #
#    Updated: 2023/02/17 19:08:48 by nfoughal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC  = map_errors.c key_moves.c  mlx_draw.c parcing.c parcing1.c \
       utils.c valid_path.c main.c get_next_line/get_next_line_utils.c \
	   get_next_line/get_next_line.c

SRCBONUS = bonus/map_errors_bonus.c bonus/key_moves_bonus.c  bonus/mlx_draw_bonus.c bonus/parcing_bonus.c bonus/parcing1_bonus.c \
       bonus/utils_bonus.c bonus/valid_path_bonus.c bonus/main_bonus.c bonus/get_next_line/get_next_line_utils.c \
	   bonus/get_next_line/get_next_line.c bonus/add_enemy.c bonus/utils1_bonus.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME} -lmlx -framework OpenGL -framework AppKit
bonus: $(OBJBONUS)
	${CC} ${CFLAGS} $(OBJBONUS) -o ${NAME} -lmlx -framework OpenGL -framework AppKit
	
%.o:%.c so_long.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
