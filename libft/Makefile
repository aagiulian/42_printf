# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiulian <arthur.giuliano@student.42.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/17 22:23:16 by agiulian          #+#    #+#              #
#    Updated: 2016/11/30 17:42:11 by agiulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = ft_atoi.c \
	  ft_memalloc.c \
	  ft_putchar_fd.c \
	  ft_strclr.c \
	  ft_strlcat.c \
	  ft_strnew.c \
	  ft_bzero.c \
	  ft_memccpy.c \
	  ft_putendl.c \
	  ft_strcmp.c \
	  ft_strlen.c \
	  ft_strnstr.c \
	  ft_isalnum.c \
	  ft_memchr.c \
	  ft_putendl_fd.c \
	  ft_strcpy.c \
	  ft_strmap.c \
	  ft_strrchr.c \
	  ft_isalpha.c \
	  ft_memcmp.c \
	  ft_putnbr.c \
	  ft_strdel.c \
	  ft_strmapi.c \
	  ft_strsplit.c \
	  ft_isascii.c \
	  ft_memcpy.c \
	  ft_putnbr_fd.c \
	  ft_strdup.c \
	  ft_strncat.c \
	  ft_strstr.c \
	  ft_isdigit.c \
	  ft_memdel.c \
	  ft_putstr.c \
	  ft_strequ.c \
	  ft_strncmp.c \
	  ft_strsub.c \
	  ft_isprint.c \
	  ft_memmove.c \
	  ft_putstr_fd.c \
	  ft_striter.c \
	  ft_strncpy.c \
	  ft_strtrim.c \
	  ft_ispunct.c \
	  ft_memset.c \
	  ft_strcat.c \
	  ft_striteri.c \
	  ft_strndup.c \
	  ft_tolower.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_strchr.c \
	  ft_strjoin.c \
	  ft_strnequ.c \
	  ft_toupper.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstsize.c \
	  ft_lstpush.c \
	  ft_tablen.c \
	  ft_tabdel.c \
	  ft_lstpop.c \
	  ft_strnjoin.c

HEAD = -Iincludes/

ECHO = printf

OBJECT = $(SRC:.c=.o)

CFLAGS = $(HEAD) -Wall -Werror -Wextra

%.o	:	%.c 
		@$(CC) $(CFLAGS) -o $@ -c $<&& $(ECHO) "\033[31m["$@"] \n\033[0m"

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	@rm -f $(OBJECT) && $(ECHO) "\033[32m[Deleting objects]\033[0m\n"

fclean: clean
	rm -f $(NAME)

re: fclean all
