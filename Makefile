$FLAGS= -ggdb -Wall 

resplan: resplan.c myListModule.o graph.o
	gcc $(FLAGS) -std=c99 myListModule.o -o resplan resplan.c

myListModule.o: myListModule.c
	gcc $(FLAGS) -std=c99 -c myListModule.c

graph.o: graph.c
	gcc $(FLAGS) -std=c99 -c graph.c

run: 
	./resplan nätverk.txt

.PHONY: run
