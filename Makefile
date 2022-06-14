# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 13:09:11 by ucivelek          #+#    #+#              #
#    Updated: 2022/05/18 13:09:14 by ucivelek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT = Libft

all: $(NAME)
	gcc server.c $(NAME) -o server
	gcc client.c $(NAME) -o client

$(NAME): $(LIBFT)
	make -C $(LIBFT)
	cp Libft/libft.a .

clean:
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)
	rm -rf server client

.PHONY: clean
