# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 14:16:33 by albrusso          #+#    #+#              #
#    Updated: 2023/11/24 14:17:32 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -g -Wall -Wextra -Werror -pthread

RM = rm -rf

SRCS = 	init.c main.c routine.c supervisor.c thread.c utils.c

$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re