CC=gcc
CFLAGS=-std=c99 -Wextra -Wall -pedantic 
LDFLAGS=-lm

ifeq ($(DEBUG),yes)
	CFLAGS += -g
	LDFLAGS =
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS =
endif

EXEC=bin/test
REP_SRC = src
REP_OBJ = obj
SRC= $(wildcard $(REP_SRC)/*.c)
OBJ= $(SRC:.c=.o)


all: 
ifeq ($(DEBUG),yes)
	@echo "Generating in debug mode"
else
	@echo "Generating in release mode"
endif
	@touch $(REP_OBJ)/qfs234fsefez12uhsfliseu134.o #Sinon '*' renvoie en tant que telle
	@mv $(REP_OBJ)/*.o $(REP_SRC)/
	@$(MAKE) $(EXEC)
	@mv $(REP_SRC)/*.o $(REP_OBJ)/
	@rm $(REP_OBJ)/qfs234fsefez12uhsfliseu134.o

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

doc:
	@doxygen documentation/Doxyfile
	
.PHONY: clean

clean:
	@rm -rf $(REP_OBJ)/*.o
	@rm -rf $(REP_SRC)/*.o

main.o:  structure_donnee.h

