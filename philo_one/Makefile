# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 20:20:15 by anatashi          #+#    #+#              #
#    Updated: 2020/12/28 19:19:37 by anatashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

CC = clang -g
FLAGS = -Wall -Wextra -Werror

HEADER_DIR	= header/

SRCS_DIR	= srcs/
SRCS_LIST	= philo_one.c\
			  freeing_memory.c\
			  init_struct.c\
			  parser.c\
			  print_message.c\
			  checking_death_and_ntepme.c\
			  tools.c\
			  stream_tools.c\
			  print_error.c

SOURCE		= $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ			= $(patsubst %.c, %.o, $(SOURCE))
D_FILE		= $(patsubst %.c, %.d, $(SOURCE))

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)

	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -pthread

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