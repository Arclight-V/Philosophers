# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 20:20:04 by anatashi          #+#    #+#              #
#    Updated: 2020/12/10 10:20:41 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

CC = clang -g
FLAGS = -Wall -Wextra -Werror

HEADER_DIR	= header/

SRCS_DIR	= srcs/
SRCS_LIST	= philo_two.c


SOURCE		= $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ			= $(patsubst %.c, %.o, $(SOURCE))
D_FILE		= $(patsubst %.c, %.d, $(SOURCE))

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)

	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -I$(HEADER_DIR) -c $< -o $@ -MD
include $(wildcard $(D_FILE))

clean:
	rm -rf $(OBJ) $(D_FILE);

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm: 
	norminette $(HEADER_DIR). $(SRCS_DIR).