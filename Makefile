# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 23:28:52 by svillalv          #+#    #+#              #
#    Updated: 2023/06/28 19:38:56 by svillalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
CC		=	gcc -pthread -fsanitize=thread -g
SRC		=	src/main.c src/check_args.c
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
OBJS	=	$(SRC:.c=.o)
COLOR	=	\033[1;36m
COLOR_RED	=	\033[1;31m
END		=	\x1b[0m

%.o: 		%.c
			@$(CC) -c $(FLAGS) $< -o $@

all:		$(NAME)

$(NAME): 	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\t$(COLOR)◕ヮ◕ﾉ･ﾟ✧$(NAME) objects compiled\n$(END)"

clean:
			@$(RM) $(OBJS)
			@echo "\n\t$(COLOR_RED)◕ヮ◕ﾉ･ﾟ✧$(NAME) objects removed\n$(END)"

fclean:
			@$(RM) $(OBJS) $(NAME)
			@echo "\n\t$(COLOR_RED)◕ヮ◕ﾉ･ﾟ✧$(NAME) objects and executable removed\n$(END)"

re:			fclean all

.PHONY:		all clean fclean re