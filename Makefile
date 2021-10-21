##
## Saverio976, 2021
## EatSleepCode
## File description:
## make the IDE EatSleepCode
##
TARGET	=	EatSleepCode

MAIN	=	main.c

SRC	=	eat_sleep_code.c	\
		eat_sleep_code_interface.c	\
		iterr_for_event.c	\
		code_text.c	\
		read_text.c	\
		utils.c	\
		free_pointer.c

OBJ	=	$(SRC:.c=.o)

LDIR	=	./lib/my

LIBS	=	-lmy

IDIR	=	./include

CC	=	gcc

CFLAGS	=	-Wall -Wextra -I$(IDIR) -L$(LDIR) $(LIBS) -l csfml-graphics

$(TARGET):	$(OBJ)
	$(CC) -o $(TARGET) $(MAIN) $(OBJ) $(CFLAGS)

all:	compil_lib $(TARGET) clean-obj

clean:
	rm -f *.o *.swp *.a *~ *.gcno *.gcda

fclean:	clean
	rm -f $(TARGET)
	cd $(LDIR) && make fclean

clean-obj:
	rm -f *.o

re:	fclean all

compil_lib:
	cd $(LDIR) && make 
