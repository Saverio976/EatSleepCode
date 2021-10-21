##
## EPITECH PROJECT, 2021
## Libmy
## File description:
## create the lib and move it to ../
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

LIB_NAME	=	libmy.a

INCLUDE_NAME	=	my.h

all:	build copy clean

re:	fclean build copy clean

build:
	gcc -c $(SRC)
	ar rc $(LIB_NAME) $(OBJ)

copy:
	cp $(LIB_NAME) ../$(LIB_NAME)
	cp $(INCLUDE_NAME) ../../include/$(INCLUDE_NAME)

clean:
	rm -f *.o

fclean:
	rm -f ../$(LIB_NAME) $(LIB_NAME)
	rm -f ../../include/$(INCLUDE_NAME)
