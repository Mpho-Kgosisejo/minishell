# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 14:59:51 by mkgosise          #+#    #+#              #
#    Updated: 2017/08/31 12:43:11 by mkgosise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

RAWSRC = main.c			ft_env.c		ft_setenv_handler.c	ft_echo.c\
		 ft_chdir.c		ft_open_app.c	ft_puterr.c\
		 ft_filter_quotes.c\
		 ft_unsetenv_handler.c			ft_update_envp_pwds.c\
		 ft_makeargs.c	ft_echo_write.c	get_env.c			show_user_name.c\
		 ft_strsplit_2.c

SRC = $(RAWSRC:%=src/%)

OBJ = $(SRC:src/%.c=%.o)

LIBFT = ./libft/

FLAGS = -Wall\
		-Wextra\
		-Werror

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBFT)
	@gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L$(LIBFT) -lft

clean:
	@rm -f $(OBJ)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean

re: fclean all
