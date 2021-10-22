# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejeon <yejeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 15:41:33 by yejeon            #+#    #+#              #
#    Updated: 2021/10/22 14:33:37 by yejeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

DIR_LIBFT	=	./libft/
DIR_SRC		=	./src/
DIR_OBJ		=	./obj/

LIB_FT		=	libft.a

SRCS		=	pipex.c \
				utils.c
OBJS		=	$(SRCS:%.c=$(DIR_OBJ)%.o)
LIBS		=	$(DIR_LIBFT)$(LIB_FT)

all:	$(NAME)

$(NAME):	$(DIR_OBJ) $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(LIBS) $(OBJS)

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(DIR_OBJ):
	@mkdir -p $@

$(LIBS):
	@make -C $(DIR_LIBFT)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@make fclean -C $(DIR_LIBFT)
	@rm -f $(NAME)

re:	fclean all

norm:
	@norminette $(DIR_SRC)*.[ch]

.PHONY: all fclean clean re norm
