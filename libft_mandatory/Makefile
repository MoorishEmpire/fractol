# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 15:21:00 by ael-most          #+#    #+#              #
#    Updated: 2025/04/10 12:51:00 by ael-most         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## VARIABLES ##
###############

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Werror -Wextra
CC_COMPILER_CALL = $(CC) $(CCFLAGS) 
AR = ar
ARFLAGS = rcs
RM = rm -f
HEADERS = libft.h

###################
#### MANDATORY ####
###################

SRC = 	ft_isalpha.c ft_isdigit.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_isalnum.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf/ft_printf.c ft_printf/ft_specifier.c \
		ft_printf/conversions_src/ft_putchar.c ft_printf/conversions_src/ft_putstr.c \
		ft_printf/conversions_src/ft_putnbr.c ft_printf/conversions_src/ft_putnbr_unsigned.c \
		ft_printf/conversions_src/ft_putnbr_hex.c ft_printf/conversions_src/ft_putptr.c


OBJ = $(SRC:.c=.o)
GET_LINE_OBJS = $(GET_LINE_SRCS:.c=.o)

############
## TARGETS ##
#############

all: $(NAME)

$(NAME): $(OBJ) $(GET_LINE_OBJS)
	@$(AR) $(ARFLAGS) $@ $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

################
### PATTERNS ###
################

%.o : %.c $(HEADERS)
	@$(CC_COMPILER_CALL) -c $< -o $@

###############
#### PHONY ####
###############

.PHONY: clean
