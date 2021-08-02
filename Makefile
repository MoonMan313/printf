# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdionna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 17:46:11 by cdionna           #+#    #+#              #
#    Updated: 2021/01/17 17:46:13 by cdionna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SOURCE = basic_str_func.c check_flags.c ft_printf.c libft_func.c parser.c\
print_type.c print_type_c.c print_type_d.c print_type_p.c print_type_s.c\
print_type_u.c print_type_x.c print_utils.c

O_FILE = $(SOURCE:.c=.o)

C_FLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(HEADER) $(O_FILE)
	ar rc $(NAME) $(O_FILE)
	ranlib $(NAME)

$(O_FILE): %.o:%.c $(HEADER)
	gcc -c $(C_FLAGS) $<

clean:
	rm -rf $(O_FILE)

fclean: clean
	rm -rf $(NAME)

re:		fclean all
	
