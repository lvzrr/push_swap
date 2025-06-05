# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 13:14:10 by jaicastr          #+#    #+#              #
#    Updated: 2025/04/30 13:21:37 by jaicastr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
SRCDIR		:=	src
SRC			:=	$(wildcard $(SRCDIR)/*.c)
INCLUDEF	:=	-I./include -I./libft/include
LIB			:=	libft/libft.a

BUILDDIR	:= build
OBJ			:= $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))
CC			:= cc
CFLAGS  	:= -Wall -Wextra -Werror $(INCLUDEF)
LDFLAGS		:= $(LIB)

all: $(NAME)
	@echo -e "\033[1;34m==> Compilation successful!\033[0m\n\n"

$(NAME): $(LIB) $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	@$(MAKE) -C libft

clean:
	@rm -rf $(BUILDDIR)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

banner:
	@echo -e "\033[1;34m==> Compiling push_swap...\033[0m\r"

.PHONY: all clean fclean re
MAKEFLAGS += --no-print-directory
