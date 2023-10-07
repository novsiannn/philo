# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:49:28 by nikitos           #+#    #+#              #
#    Updated: 2023/10/07 19:50:53 by nikitos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = src/main.c
OBJS = ${SRCS:.c=.o}

RM = rm -f

GREEN = \033[0;32m
BLUE = \033[1;34m
CYAN = \033[1;36m
PURPLE = \033[0;35m
RED = \033[0;31m
YELLOW = \033[1;33m
INC = inc
# -fsanitize=address -g -I $(INC)
CFLAGS = -Wall -Wextra -Werror -g

all:	$(NAME)

$(NAME):	$(OBJS)
			@echo "\n"
			@echo "$(YELLOW)Starting compiling...$(DEF_COLOR)"
			@echo "\n"
			@echo "$(CYAN)."
			gcc $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n"
			@echo "$(GREEN)MINISHELL compiled!$(DEF_COLOR)"

clean:
		@echo "$(RED)Starting deleting..."
		$(RM) $(OBJS)
		@echo "\n"
		@echo "$(YELLOW)Objects removed!"
		@echo "\n"

fclean: clean
		@echo "$(RED)Starting deleting..."
		${RM} $(NAME)

re:		fclean all

.PHONY:		all clean fclean re