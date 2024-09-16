# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rode-lim <rode-lim@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/13 19:14:54 by rode-lim          #+#    #+#              #
#    Updated: 2024/09/16 15:23:36 by rode-lim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
CC 			= cc
CFLAGS    	= -Wall -Wextra -Werror -g -pthread

SRC_DIR		= src/
OBJ_DIR		= obj

MAIN 		= src/main.c \
			  src/error_check.c \
			  src/utils.c \
			  src/init.c  \
			  src/init_threads.c \
			  src/routine.c \
			  src/monitor.c \
			  src/norm.c

SOURCE = $(MAIN)
		  
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(MAIN))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run