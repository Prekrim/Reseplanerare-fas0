$FLAGS=-std=c99 -ggdb -Wall


resplan: resplan.c myListModule.o
	gcc $(FLAGS) myListModule.o -o resplan resplan.c

myListModule.o: myListModule.c
	gcc $(FLAGS) -c myListModule.c
run: 
	./resplan

.PHONY: run
