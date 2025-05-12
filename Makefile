# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: justlaw <justlaw@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 11:49:30 by justlaw           #+#    #+#              #
#    Updated: 2025/05/12 22:04:14 by justlaw          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus