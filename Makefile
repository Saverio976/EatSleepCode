##
## Saverio976, 2021
## EatSleepCode
## File description:
## make the IDE EatSleepCode
##
TARGET	=	EatSleepCode

PREFIX	=	src/

MAIN	=	$(PREFIX)main.c

SRC	=	$(PREFIX)eat_sleep_code.c	\
		$(PREFIX)eat_sleep_code_interface.c	\
		$(PREFIX)iterr_for_event.c	\
		$(PREFIX)code_text.c	\
		$(PREFIX)read_text.c	\
		$(PREFIX)utils.c	\
		$(PREFIX)free_pointer.c

OBJ	=	$(SRC:.c=.o)

LDIR	=	./lib/my

LIBS	=	-lmy

IDIR	=	./include

CC	=	gcc

CFLAGS	=	-Wall -Wextra -I$(IDIR) -L$(LDIR) $(LIBS) -l csfml-graphics

$(TARGET):	$(OBJ)
	make compil_lib
	$(CC) -o $(TARGET) $(MAIN) $(OBJ) $(CFLAGS)

all:	$(TARGET) clean-obj

clean:
	rm -f $(PREFIX)*.o $(PREFIX)*.swp $(PREFIX)*.a $(PREFIX)*~ *.gcno *.gcda

fclean:	clean
	rm -f $(TARGET)
	cd $(LDIR) && make fclean

clean-obj:
	rm -f *.o

re:	fclean all

compil_lib:
	cd $(LDIR) && make 
