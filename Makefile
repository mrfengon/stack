CC = gcc

CCFLAGS = -g

OBJ = main.o sort.o funcs.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) -o main $(OBJ)

main.o: main.c sort.h

funcs.o: funcs.h

funcs.c: funcs.h

sort.c: sort.h

clean:
	@rm -r *.o main