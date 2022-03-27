# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmumm <kmumm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 19:57:03 by kmumm             #+#    #+#              #
#    Updated: 2022/03/22 04:31:43 by kmumm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

UTILS = mandatory/main.c\
		mandatory/get_next_line.c\
		mandatory/get_next_line_utils.c\
		mandatory/list.c\
		mandatory/map.c\
		mandatory/errors_handlers.c\
		mandatory/pic_draw.c\
		mandatory/ft_printf.c\
		mandatory/player.c\

UTILS_OBJS = $(UTILS:.c=.o)

HEADER	=	mandatory/utils.h

NAME_BONUS = so_long_bonus

UTILS_BONUS = bonus/main.c\
		bonus/get_next_line.c\
		bonus/player_animation.c\
		bonus/get_next_line_utils.c\
		bonus/list.c\
		bonus/map.c\
		bonus/errors_handlers.c\
		bonus/pic_draw.c\
		bonus/player.c\

UTILS_BONUS_OBJS = $(UTILS_BONUS:.c=.o)

HEADER_BONUS = bonus/utils.h

LINKS = -lmlx -framework OpenGL -framework AppKit


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f
#UTILS_HEADER = utils/utils.h

#LIB_PATH = utils/lib.a

#GREEN = \033[0;32m
#RED = \033[0;31m
#RESET = \033[0m

#lib: $(UTILS_OBJS) $(UTILS_HEADER)
#	ar rcs $(LIB_PATH) $?
#	#ranlib $(LIB_PATH)

all:		$(NAME)

$(NAME):	$(UTILS_OBJS) $(HEADER)
			$(CC) $(UTILS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAME_BONUS):	$(UTILS_BONUS_OBJS) $(HEADER_BONUS)
			$(CC) $(UTILS_BONUS) $(MLXFLAGS) $(CFLAGS) -o $(NAME_BONUS)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus:		$(NAME_BONUS)

clean:
			$(RM) $(UTILS_OBJS) $(UTILS_BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
