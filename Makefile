# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arkim <arkim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 16:46:43 by arkim             #+#    #+#              #
#    Updated: 2019/10/30 18:21:23 by arkim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

DIR_S	=	./srcs/
DIR_O	=	./objs/
DIR_I	=	./includes/

SRCS	=	$(wildcard $(DIR_S)*.c)
OBJS	=	$(addprefix $(DIR_O), $(notdir $(SRCS:.c=.o)))

GR		=	\033[0;32m
RD		=	\033[0;31m
YE		=	\033[0;33m
PU		=	\033[1;35m
EOC		=	\033[0m
CHECK	=	$(GR)\xE2\x9C\x94$(EOC)
BOLD	=	\033[1m
ITALIC	=	\033[3m

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n\033[K$(EOC)\t[ $(CHECK) ]$(YE)  LIBFT :  $(GR)Compiled$(EOC)"

$(DIR_O)%.o: $(DIR_S)%.c $(DIR_I)
	@mkdir -p $(DIR_O)
	@echo "\n\033[K\033[K$(EOC)\t[   ]$(YE)  LIBFT :  $(GR)Compiling  $(ITALIC)$<$(EOC)\033[2A";
	@$(CC) $(CFLAGS) -I $(DIR_I) -o $@ -c $<

clean :
	@/bin/rm -rf $(DIR_O)

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\n\033[K$(EOC)\t[ $(CHECK) ]$(YE)  LIBFT :  $(GR)Removed$(EOC)"

re : fclean all

.PHONY: all clean fclean re
