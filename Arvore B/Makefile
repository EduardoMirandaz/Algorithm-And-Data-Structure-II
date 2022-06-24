UTIL=Student.c Util.c Database.c Btree.c
MAIN=Main.c
BINARY=executavel.exe
T-INPUT=testes/4.in
T-OUTPUT=testes/4.out
S-OUTPUT=out.out

all:
	gcc -g -Werror -Wextra -Wall $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

input:
	./$(BINARY) < $(T-INPUT)

zip:
	@zip -r $(BINARY).zip Student.c Util.c Database.c Btree.c Main.c Makefile nusp.txt

dev:
	gcc -O3 -march=native $(UTIL) $(MAIN) -o $(BINARY) && ./$(BINARY) < $(T-INPUT) > $(S-OUTPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

test:
	gcc -g $(UTIL) $(MAIN) -o $(BINARY) && ./$(BINARY) < $(T-INPUT) > $(S-OUTPUT) && diff $(S-OUTPUT) $(T-OUTPUT)
#cat -e -t -v Makefile -> problemas com makefile
#no windows, BINARY deve estar como "executavel.exe", no linux apenas "executavel"