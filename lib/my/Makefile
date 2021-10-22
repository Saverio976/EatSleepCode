##
## EPITECH PROJECT, 2021
## Libmy
## File description:
## create the lib and move it to ../
##

SRC	=	file_create.c	\
		file_is_exists.c	\
		file_is_file.c	\
		file_is_readable.c	\
		file_is_writable.c	\
		file_openreadonly.c	\
		my_putstr.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_arraylen.c

OBJ	=	$(SRC:.c=.o)

LIB_NAME	=	libmy.a

INCLUDE_NAME	=	my.h

CFLAGS	=	-Wall -Wextra

all:	build

re:	fclean build

build:	$(OBJ)
	ar rc $(LIB_NAME) $(OBJ)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(LIB_NAME)
