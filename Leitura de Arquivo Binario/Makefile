BINARY=exe
INPUT = "./testes/1.in"
STREAM = fileHandler.c student.c operations.c

all:
	gcc -O3 -march=native -Wall -g main.c $(STREAM) -o $(BINARY) -lm

run:
	./$(BINARY)

input:
	./$(BINARY) < $(INPUT) > out.txt && ./$(BINARY) < $(INPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)