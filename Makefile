CC = gcc

CCFLAGS = -g

OBJ = funcs.o sort.o main.o

.SUFFIXES: .c .o

main: $(OBJ)
	@$(CC) $(CCFLAGS) $(OBJ) -o main

main.o: funcs.o sort.o
	$(CC) -c $(CCFLAGS) main.c

funcs.o: funcs.h stack.h funcs.c
	$(CC) -c $(CCFLAGS) funcs.c

sort.o: funcs.o sort.c
	$(CC) -c $(CCFLAGS) sort.c

clean:
	@rm -f *.o *.gch main