BIN=test
SRC=$(wildcard src/core/*.c)
OBJ=$(SRC:.c=.o)

all:
	make -C src/core -w
	gcc test.c -o $(BIN) $(OBJ)


clean:
	make -C src/core -w clean
	rm $(BIN)
	
