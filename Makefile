#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/04/19 17:12:15 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB = ft_printf/libftprintf.a
SRC = main.c\
	  ft_error.c\
	  list_management.c\
	  action1.c\
	  print_list.c
OBJ = 
SRCO = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) -o $(addprefix $(OBJ),$@) -c $< $(FLAG)

$(NAME): $(SRCO)
	make -C ft_printf
	gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

clean:
	make -C ft_printf clean
	rm -f $(addprefix $(OBJ),$(SRCO))

fclean: clean
	make -C ft_printf fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
